#ifndef _FOURIER_H_
#define _FOURIER_H_

//calcula a transformada discreta de fourier
complex double *dft(unsigned char *, int);
//calcula a inversa da transformada discreta de fourier
unsigned char *dft_inversa(complex double *, int);
//ordena os coeficientes de maneira decrescente pela sua magnitude
double *ordena_coeficiente(complex double *, int *, int);
//zera a magnitude dos coeficientes que tem a posicao maiores que C
void zera_coeficiente(complex double *, int *, int, int);



#endif
