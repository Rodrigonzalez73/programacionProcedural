void carga (int matriz [filas][columnas],int i, int j){
    if(i<filas){
        if (j<columnas){
            scanf("%d",&matriz[i][j]);
            carga(matriz,i,j+1);
        } else {
            carga(matriz,i+1,j=0);
        }
    }
    else{
        return;
    }
}