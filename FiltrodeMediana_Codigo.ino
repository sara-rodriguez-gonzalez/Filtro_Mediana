int c, d, n=7, med=3;
double lectura, a[7]={0}, aux[7]={0}, swap;

void setup() {
  Serial.begin(9600);
  pinMode(A0,INPUT);
}

void loop() {
  
  lectura = analogRead(A0);
  //lectura = (lectura*30)/1023; //LM35
  lectura = (lectura*5)/1023; //PULSO RUIDOSO Y SENO
  a[n-1] = lectura;

  for(c=0; c<n; c++)
  {
    aux[c]=a[c];
  }
   
  //Saca la mediana
  for (c = 0 ; c < n - 1; c++)
  {
    for (d = 0 ; d < n - c - 1; d++)
    {
      if (a[d] > a[d+1]) 
      {
        swap       = a[d];
        a[d]   = a[d+1];
        a[d+1] = swap;
      }
    }
  }

  Serial.println(a[med]);  
  //Serial.println(lectura);

  for(c=0; c<n; c++)
  {
    a[c]=aux[c];
  }
  
  for(c=0; c<(n-1); c++)
  {
    a[c] = a[c+1]; 
  }
  
  delay(10);
}
