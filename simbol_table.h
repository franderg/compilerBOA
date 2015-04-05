struct ElementoLista {
	char *name;
	int type;	/* 1 entero
				 * 3 decimal
				 * 3 booleano
				 * 4 string
				 * 5 complex
				 */
	int constant;
	struct ElementoLista *siguiente;
};
typedef struct ElementoLista Elemento;

Elemento *inicio = NULL;


/**
 * insercion al inicio de la lista
 * @return -1 si hay un error, 0 de lo contrario 
 */
int ins_inicio_lista (char *pName, int pType, int pConstant){
 	Elemento *nuevo_elemento;
  	if ((nuevo_elemento = (Elemento *) malloc (sizeof (Elemento))) == NULL)
    	return -1;
  	if ((nuevo_elemento->name = (char *) malloc (strlen(pName)+1)) == NULL)
    	return -1;
  	strcpy (nuevo_elemento->name, pName);

  	nuevo_elemento->constant = pConstant;
  	nuevo_elemento->type = pType;
  	nuevo_elemento->siguiente = inicio;
  	inicio = nuevo_elemento;
  	return 0;
}

/**
 * busca un elemento en la lista
 * @return 1 si el elemento se encuentra en la lista, 0 de lo contrario 
 */
int buscar_elemento (char *pName){
  	Elemento *actual;
  	actual = inicio;
  	while (actual != NULL){
  		if (!strcmp(actual->name, pName))
  			return 1;
  		actual = actual->siguiente;
  	}
  	return 0;
}

/**
 * busca un elemento en la lista
 * @return 1 si el elemento se encuentra en la lista, 0 de lo contrario 
 */
Elemento * obtener_elemento (char *pName, int pType){
  	Elemento *actual;
  	actual = inicio;
  	while (actual != NULL){
  		if (!strcmp(actual->name, pName) && actual->type==pType)
  			return actual;
  		actual = actual->siguiente;
  	}
  	return NULL;
}

/**
 * busca un elemento en la lista
 * @return 1 si el elemento se encuentra en la lista, 0 de lo contrario 
 */
int obtener_tipo_elemento (char *pName){
  	Elemento *actual;
  	actual = inicio;
  	while (actual != NULL){
  		if (!strcmp(actual->name, pName))
  			return actual->type;
  		actual = actual->siguiente;  		
  	}
  	return -1;
}


void visualizacion (){
	printf("****	TABLA DE SIMBOLOS 	****\n");
  	Elemento *actual;
  	actual = inicio;
  	while (actual != NULL){
    	printf ("%s 		", actual->name);
    	if (actual->type==1) printf ("entero");
    	else if (actual->type==2) printf ("decimal");
    	else if (actual->type==3) printf ("booleano");
    	else if (actual->type==4) printf ("string");
    	else if (actual->type==5) printf ("complejo");
    	if (actual->constant==1)
    		printf("		constante\n");
    	else
    		printf("\n");
      	actual = actual->siguiente;
  	}
  	printf("************************************\n");
}