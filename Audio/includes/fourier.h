#ifndef
#define

//calcula a transformada discreta de fourier
complex double *dft(unsigned char *, int);
//calcula a inversa da transformada discreta de fourier
unsigned char *dft_inversa();
//reduz a magnitude do coeficiente
double *reduz_coeficiente();
//zera a magnitude do coeficiente
void zera_coeficiente();



#endif
