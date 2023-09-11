int separa(int *v, int l, int r){
  int c = v[r];
  int j = l;
  for(int k = l; k < r; k++){
    if(v[k] < c){
      int aux = v[j];
      v[j] = v[k];
      v[k] = aux;
      j++;
    }
  }
  int aux = v[j];
  v[j] = v[r];
  v[r] = aux;
  return j;
}

void quicksort(int *v, int l, int r){
  int j;
  if(r<=l)  return;
  j = separa(v,l,r);
  quicksort(v,l,j-1);
  quicksort(v,j+1,r);
}