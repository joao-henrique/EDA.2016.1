	/*	else if((p->info < aux->info) && (aux->ant != NULL) && (p->info > aux->ant->info)) {
			p -> prox = aux;
			p -> ant = aux -> ant;
			aux -> ant = p;
			p -> ant -> prox = p;
		} */




/* void ordena_lista_inverso(cab *l, no *p) {
	int i;
	no *aux = l->inilist;
	for(i = 0; i<l->nelem; i++) {
		if(l->nelem == 1){ 
			if(p->info < aux->info) {
				aux->prox = p;
				p -> ant = aux;
				l -> fimlist = p;
				l->nelem += 1;
				return;
			}
			else {
				aux -> ant = p;
				p -> prox = aux;
				l -> inilist = p;
				l->nelem += 1;
				return;
			}
		}
		if((p->info > aux->info) && (aux->ant == NULL)) {
			p -> prox = aux;
			p -> ant = NULL;
			aux -> ant = p;
			l->inilist = p;
			l->nelem += 1;
			return;
		}
		else if((p->info > aux->info) && (aux->ant != NULL) && (p->info < aux->ant->info)) {
			p -> prox = aux;
			p -> ant = aux->ant;
			aux -> ant = p;
			p -> ant -> prox = p;
			l->nelem += 1;
			return;
		}
		if((p->info < aux->info) && (aux->prox == NULL)) {
			p -> ant = aux;
			p -> prox = NULL;
			aux -> prox = p;
			l->fimlist = p;
			l->nelem += 1;
			return;
		}
	/*	else if((p->info < aux->info) && (aux->ant != NULL) && (p->info > aux->prox->info)) {
			p -> ant = aux;
			p -> prox = aux -> prox;
			aux -> prox = p;
			p -> prox -> ant = p;
		} 
		aux = aux->prox;
	} // fim for
	printf("\nOcorreu algum erro na ordenacao. Elemento nao adicionado.\n");
} */

/*void ordena(cab *l) {
	int i;
	no *aux = l->inilist, *aux3 = (no*) malloc(sizeof(no));
	for(i = 0; i<l->nelem; i++) {
		no *aux2 = l->inilist;
		for(i = 0; i<l->nelem; i++) {
			if(l->nelem == 1){
				return;
			}
			if((aux->info > aux2->info) && (aux2->prox == NULL)) {
				aux3 = aux;
				aux -> ant = aux2;
				aux -> prox = NULL;
				aux2 -> prox = aux;
				aux2 -> ant = NULL;
				l->fimlist = aux;
				break;
			}
			else if((aux->info > aux2->info) && (aux2->prox != NULL) && (aux->info < aux2->prox->info)) {
				aux3 = aux;
				aux -> ant = aux2;
				aux -> prox = aux2->prox;
				aux2 -> prox = aux;
				aux -> prox -> ant = aux;
				break;
			}
			if((aux->info < aux2->info) && (aux2->ant == NULL)) {
				aux3 = aux;
				aux -> prox = aux2;
				aux -> ant = NULL;
				aux2 -> ant = aux;
				aux2 -> prox = NULL;
				l->inilist = aux;
				break;
			}
		/*	else if((aux->info < aux->prox->info) && (aux->prox->ant != NULL) && (aux->info > aux->prox->ant->info)) {
				aux -> prox = aux -> prox -> prox;
				aux -> ant = aux -> prox -> ant;
				aux -> prox -> ant = aux;
				aux -> ant -> prox = aux;
			} 
			aux2 = aux2 -> prox;
		} // fim for
		aux = aux->prox;
	} // fim for
} */

/* void ordena_inverso(cab *l) {
	int i;
	no *aux2 = l->inilist, *aux3 = (no*) malloc(sizeof(no));
//	for(i = 0; i<l->nelem; i++) {
		no *aux = l->inilist;
		for(i = 0; i<l->nelem; i++) {
			if(l->nelem == 1) 
				return;
			else if(aux->info > aux2->info) {
				aux3 = aux;
				aux -> prox = aux2;
				aux -> ant = aux2->ant;
				aux2 -> ant = aux3;
				aux2 -> prox = aux3->prox;
				if(aux->ant == NULL) 
					l -> inilist = aux;
				else if(aux->prox == NULL)
					l -> fimlist = aux;
				if(aux2->ant == NULL)
					l -> inilist = aux2;
				else if(aux2->prox == NULL)
					l -> fimlist = aux2;
			}
		/*	else if((aux->info > aux2->info) && (aux->ant != NULL) && (aux->info < aux2->ant->info)) {
			//	aux3 = aux;
				aux -> prox = aux2;
				aux -> ant = aux2->ant;
				aux2 -> ant = aux;
				aux -> ant -> prox = aux;
				break;
			}
			else if((aux->info < aux2->info) && (aux2->prox == NULL)) {
				//aux3 = aux;
				aux -> ant = aux2;
				aux -> prox = NULL;
				aux2 -> prox = aux;
				aux2 -> ant = NULL;
				l -> fimlist = aux;
				break;
			}
			else if((aux->info < aux->prox->info) && (aux->prox->prox != NULL) && (aux->info > aux->prox->prox->info)) {
				aux -> ant = aux -> prox;
				aux -> prox = aux -> prox -> prox;
				aux -> prox -> prox = aux;
				aux -> prox -> ant = aux;
			}
			aux = aux->prox;
		} // fim for
		aux2 = aux2->prox;
	//} // fim for
} */

