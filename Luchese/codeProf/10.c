#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// Scrivere una funzione che calcoli il massimo 
// guadagno possibile con una sola operazione 
// di acquisto e una di vendita, e che restituisca 
// in quali giorni queste devono essere effettuate
// returns the maximum gain
float max_gain_wrong (float *btc, int btc_size) {
	// missing test sell after buy
	// trova il valore massimo
	float maximum = btc[0];
	for (int i=0; i<btc_size; i++)
		if ( btc[i] > maximum ) maximum = btc[i];
	// trova il valore minimo 
	float minimum = btc[0];
	for (int i=0; i<btc_size; i++)
		if ( btc[i] < minimum ) minimum = btc[i];

	float gain = maximum - minimum;
	return gain;
}



float max_gain (float *btc, int btc_size,
				int *best_buy, int *best_sell) {
	// if (btc_size<2) return 0.0;
	float gain = 0.0; 
	for (int buy=0; buy<btc_size-1; buy++) {
		for (int sell=buy+1; sell<btc_size; sell++) {
			float current_gain = btc[sell] - btc[buy];
			if (current_gain > gain) {
				gain = current_gain;
				*best_buy = buy;
				*best_sell = sell;
			}
		}
	}
	return gain;
}





void print_array_v0(int *a, int a_size) {
	printf("[");
	for (int i=0; i<a_size; i++)
		printf(" %d", *(a+i) );
	printf(" ]\n");
}







void print_array(int *a_begin, int *a_end) {
	printf("[");
	while ( a_begin != a_end ) {
		printf(" %d", *(a_begin) );
		a_begin++;
	}
	printf(" ]\n");
}



// dato un array di interi
// costruire un nuovo array che contenga solo i numeri pari
void even_v0( int *src, int src_size, 
		   int* dest, int *dest_size) {
	// loop over src
	*dest_size = 0;
	for (int i=0; i<src_size; i++) {
		//  aggiungi solo i pari a dest
		if ( src[i]%2 == 0 ) {
			dest[*dest_size] = src[i];
			(*dest_size)++;
		}
	}
}









void even( int *src, int src_size, 
		   int* dest, int *dest_size) {
	int *dest_i = dest;
	int *end = src + src_size;
	while (src != end) {
		if ( *src%2 == 0 )
			*(dest_i++) = *src;
		src++;
	}
	*dest_size = dest_i - dest;
}





// dati due array, dire se uno è contenuto nell'altro
// es. [1,2,3] è contenuto in [8,9,0,1,2,3,4,5,6]
//      ma non è contenuto in [1,0,2,0,3,0]
	// A è contenuto in B


bool is_prefix( int *A, int A_size, 
				int *B, int B_size) {
	if (A_size>B_size) return false;
	for(int i=0; i<A_size; i++)
		if (A[i]!=B[i])
			return false;
	return true;
}

bool is_contained(  int *A, int A_size, 
					int *B, int B_size) {
	if (A_size > B_size) 
		return false;
	for (int b_i=0; b_i<B_size; b_i++) {
		if ( is_prefix (A, A_size, B+b_i, B_size-b_i) )
			return true;
	}
	return false;
}







int main(void) { 
	int aa[] = {1,2,3};
	int bb[] = {8,9,0,1,2,3,4,5,6};
	printf("is contained: %d \n", 
		is_contained(aa, 3, bb, 9) );


	return 0;

	int v[] = {1,2,3,4,5,6};
	int v2[6];
	int v2_size;
	even(v, 6, v2, &v2_size);
	print_array(v2, v2+v2_size);




	return 0; 













	return 0;
	int a[4] = {1,2,3,4};

	print_array(a, a+4);


	int *p = &a[0];
	int *p2 = p + 1;



	&(p[1]) == p + 1; // indirizzo_base (p) 
	                  // + offset (1) * sizeof (int)
	p[1] == *(p+1);


	p[1] == 1[p]; // mai ....



	return 0;

	int buy, sell;
	float btc[] = {10923.63, 10679.14, 10621.66, 10804.00, 10684.43, 10565.49, 10585.16, 10623.33, 10787.62, 10848.83, 10721.33, 10774.43, 10754.44, 10702.29, 10745.55, 10225.86, 10538.46, 10462.26, 10938.27, 11094.35, 10944.59, 10948.99, 10974.90, 10796.95, 10680.84, 10323.76, 10442.17, 10400.91, 10363.14, 10242.35, 10131.52, 10369.56, 10280.35, 10169.57, 10511.81, 10245.30, 11414.03, 11970.48, 11680.82, 11711.51, 11506.87, 11542.50, 11323.40, 11488.36, 11366.14, 11774.60, 11664.85, 11681.83, 11592.49, 11878.37, 11758.28, 11991.23, 12254.40, 11892.80, 11865.70, 11768.87, 11784.14, 11584.93, 11410.53, 11878.11, 11675.74, 11754.05, 11601.47, 11779.77, 11747.02, 11205.89, 11246.35, 11053.61, 11759.59, 11323.47, 11111.21, 11100.47, 10912.82, 10990.87, 9905.17, 9677.11, 9536.89, 9581.07, 9525.36, 9374.89, 9164.23, 9185.82, 9159.04, 9151.39, 9132.23, 9192.84, 9243.21, 9243.61, 9276.50, 9240.35, 9278.81, 9277.97, 9428.33, 9252.28, 9375.47, 9073.94, 9132.49, 9087.30, 9123.41, 9228.33, 9137.99, 9190.85, 9143.58, 9045.39, 9162.92, 9264.81, 9313.61, 9629.66, 9648.72, 9303.63, 9332.34, 9288.02, 9411.84, 9480.26, 9538.02, 9450.70, 9386.79, 9475.28, 9480.84, 9321.78, 9870.09, 9795.70, 9771.49, 9758.85, 9653.68, 9665.53, 9800.64, 9656.72, 9529.80, 10167.27, 9461.06, 9700.41, 9439.12, 9525.75, 9181.02, 8835.05, 8906.93, 8790.37, 9209.29, 9182.58, 9081.76, 9522.98, 9729.04, 9726.57, 9670.74, 9377.01, 9328.20, 9733.72, 9269.99, 8804.48, 8601.80, 8756.43, 9593.90, 9842.67, 9951.52, 9268.76, 9003.07, 8912.65, 8897.47, 8988.60, 8864.77, 8658.55, 8801.04, 7807.06, 7795.60, 7679.87, 7569.94, 7550.90, 7429.72, 7117.21, 6880.32, 6881.96, 7189.42, 7257.66, 7096.18, 7116.80, 6642.11, 6842.43, 6845.04, 6971.09, 6859.08, 6865.49, 7302.09, 7334.10, 7176.41, 7271.78, 6791.13, 6867.53, 6733.39, 6793.62, 6606.78, 6438.64, 6429.84, 5922.04, 6242.19, 6469.80, 6716.44, 6681.06, 6734.80, 6416.31, 5830.25, 6185.07, 6198.78, 6191.19, 5238.44, 5225.63, 5014.48, 5392.31, 5200.37, 5563.71, 4970.79, 7911.43, 7909.73, 7923.64, 8108.12, 8909.95, 9122.55, 9078.76, 8755.25, 8787.79, 8869.67, 8562.45, 8599.51, 8672.46, 8784.49, 8820.52, 9341.71, 9650.17, 9924.52, 9663.18, 9686.44, 9608.48, 9633.39, 10142.00, 9690.14, 9934.43, 9889.42, 10312.12, 10214.38, 10326.05, 10208.24, 9856.61, 10116.67, 9865.12, 9795.94, 9729.80, 9613.42, 9180.96, 9293.52, 9344.37, 9392.88, 9350.53, 9508.99, 9316.63, 9358.59, 8909.82, 8596.83, 8367.85, 8445.43, 8406.52, 8680.88, 8745.89, 8657.64, 8706.25, 8942.81, 8929.04, 8723.79, 8807.01, 8827.76, 8144.19, 8192.49, 8037.54, 8166.55, 7879.07, 8079.86, 8163.69, 7769.22, 7411.32, 7410.66, 7344.88, 6985.47, 7200.17, 7193.60, 7293.00, 7422.65, 7317.99, 7290.09, 7238.97, 7275.16, 7322.53, 7355.63, 7511.59, 7191.16, 7218.82, 7202.84, 7276.80, 6640.52, 6932.48, 7152.30, 7124.67, 7269.68, 7243.13, 7217.43, 7278.12, 7400.90, 7564.35, 7556.24, 7547.00, 7448.31, 7252.03, 7320.15, 7321.99, 7424.29, 7569.63, 7761.24, 7463.11, 7531.66, 7218.37, 7146.13, 7047.92, 7397.80, 7296.58, 7642.75, 8027.27, 8206.15, 8309.29, 8577.98, 8550.76, 8491.99, 8708.10, 8808.26, 8815.66, 8757.79, 9055.53, 8813.58, 8804.88, 9267.56, 9360.88, 9342.53, 9412.61, 9235.35, 9324.72, 9261.10, 9199.58, 9205.73, 9427.69, 9256.15, 9551.71, 9244.97, 8660.70, 7493.49, 7514.67, 8078.20, 8243.72, 8222.08, 7988.56, 7973.21, 8103.91, 8047.53, 8205.37, 8374.69, 8321.01, 8336.56, 8321.76, 8586.47, 8595.74};
	float gain = max_gain ( btc, 350, &buy, &sell);
	printf("maximum gain: %f \n", gain);
	printf("buy / sell: %d / %d \n", buy, sell);


  	return 0;
}