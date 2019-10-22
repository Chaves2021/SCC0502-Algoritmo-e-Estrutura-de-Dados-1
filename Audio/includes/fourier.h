#ifndef
#define

//calcula a transformada discreta de fourier
complex double *dft(unsigned char *, int);
//calcula a inversa da transformada discreta de fourier
unsigned char *dft_inversa(complex double *, int);
//reduz a magnitude do coeficiente
double *reduz_coeficiente(complex double *, int *, int);
//zera a magnitude do coeficiente
void zera_coeficiente();



#endif
