
int rgbToCMYK(int r, int g, int b, double *c, double *m, double *y, double *k);

int cmykToRGB(double c, double m, double y, double k, int *r, int *g, int *b);


int cmykToRGB(double c, double m, double y, double k, int *r, int *g, int *b){

int ptr_r = *r; 

int ptr_g = *g; 

int ptr_b = *b; 

*r = (255) * (1-c) * (1-k);

*g = (255) * (1-m) * (1-k);

*b = (255) * (1-y) * (1-k);

if( (ptr_r == *r  ) || (ptr_g == *g) || (ptr_b == *b)){

return false;

}

return true;

}

int max(int a,int b, int c){

if(a>=b && a>=c){
  return a;
}

else if( b>=a && b>=c){

  return b;

}

return c;

}
int rgbToCMYK(int r, int g, int b, double *c, double *m, double *y, double *k){

double M = *m;

double C = *c; 

double Y = *y; 

double K = *k; 


r = r/255; 

g = g/255;

b = b/255;

*k = 1 - ( max(r,g,b) ); 

*c = (1- r- *k) / (1-*k);

*m = (1 - g -*k) / (1-*k);

*y = (1-b-*k) / (1-*k);

if( (M == *m) || (C == *c) || (Y==*y) || (K==*k) ){

return false;

}

return true;

}