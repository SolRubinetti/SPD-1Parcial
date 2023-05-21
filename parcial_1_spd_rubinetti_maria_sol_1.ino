// Rubinetti Maria Sol 1D

#define LED_ROJA A0
#define LED_VERDE A1
#define PIN_A 7
#define PIN_B 8
#define PIN_C 9
#define PIN_D 10
#define PIN_E 11
#define PIN_F 13
#define PIN_G 12
#define PULSADOR_SUBIR 1
#define PULSADOR_BAJAR 2
#define PULSADOR_PARAR 3

int pisoActual = 0;
bool flagSubida = true;
bool flagBajada = false;
bool flagFrenar = false;

void setup()
{
  pinMode(LED_ROJA, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
  pinMode(PIN_A, OUTPUT);
  pinMode(PIN_B, OUTPUT);
  pinMode(PIN_C, OUTPUT);
  pinMode(PIN_D, OUTPUT);
  pinMode(PIN_E, OUTPUT);
  pinMode(PIN_F, OUTPUT);
  pinMode(PIN_G, OUTPUT);
  pinMode(PULSADOR_SUBIR, INPUT);
  pinMode(PULSADOR_BAJAR, INPUT);
  pinMode(PULSADOR_PARAR, INPUT);
  
}

void subirPisos(){
	if (flagSubida != true)
	{	
		flagSubida = true;
	}
}
void pararDeSubir(){
	if (flagSubida != false)
	{
		flagSubida = false;
	}
}

void bajarPisos(){
	if (flagBajada != true)
	{
      
		flagBajada = true;
	}
}
void pararDeBajar(){
	if (flagBajada != false)
	{
		flagBajada = false;
	}
}

void frenarMontacargas(){
	if (flagFrenar != false)
	{
		flagFrenar = true;
	}
  
}
  void detenerMontacargas(){
    if (flagFrenar){
      digitalWrite(LED_ROJA,HIGH);
      digitalWrite(LED_VERDE,LOW);
    }
  }

void modificarSubidaPisos(){
	pisoActual = pisoActual + 1;
}

void modificarBajadaPisos() {
	pisoActual = pisoActual - 1;
}
void mostrarCero() {
  digitalWrite(PIN_A, HIGH);
  digitalWrite(PIN_B, HIGH);
  digitalWrite(PIN_C, HIGH);
  digitalWrite(PIN_D, HIGH);
  digitalWrite(PIN_E, HIGH);
  digitalWrite(PIN_F, HIGH);
}

void mostrarUno(){
  	digitalWrite(PIN_B, HIGH);
  	digitalWrite(PIN_C, HIGH);
}

void mostrarDos(){
  	digitalWrite(PIN_A, HIGH);
    digitalWrite(PIN_B, HIGH);
  	digitalWrite(PIN_G, HIGH);
    digitalWrite(PIN_E, HIGH);
    digitalWrite(PIN_D, HIGH);
}

void mostrarTres(){
    digitalWrite(PIN_A, HIGH);
  	digitalWrite(PIN_B, HIGH);
  	digitalWrite(PIN_D, HIGH);
  	digitalWrite(PIN_C, HIGH);
  	digitalWrite(PIN_G, HIGH);
}

void mostrarCuatro(){
 	digitalWrite(PIN_F, HIGH);
  	digitalWrite(PIN_G, HIGH);
    digitalWrite(PIN_B, HIGH);
    digitalWrite(PIN_C, HIGH);
}

void mostrarCinco(){
  	digitalWrite(PIN_A, HIGH);
    digitalWrite(PIN_F, HIGH);
    digitalWrite(PIN_G, HIGH);
    digitalWrite(PIN_C, HIGH);
    digitalWrite(PIN_D, HIGH);
}

void mostrarSeis(){
    digitalWrite(PIN_A, HIGH);
    digitalWrite(PIN_C, HIGH);
    digitalWrite(PIN_D, HIGH);
    digitalWrite(PIN_E, HIGH);
    digitalWrite(PIN_F, HIGH);
    digitalWrite(PIN_G, HIGH);
}

void mostrarSiete(){
    digitalWrite(PIN_A, HIGH);
    digitalWrite(PIN_B, HIGH);
    digitalWrite(PIN_C, HIGH);
    digitalWrite(PIN_G, LOW);
}

void mostrarOcho(){
    digitalWrite(PIN_A,HIGH);
    digitalWrite(PIN_B, HIGH);
    digitalWrite(PIN_C, HIGH);
    digitalWrite(PIN_D, HIGH);
    digitalWrite(PIN_E, HIGH);
    digitalWrite(PIN_F, HIGH);
    digitalWrite(PIN_G, HIGH);
}

void mostrarNueve(){
    digitalWrite(PIN_A, HIGH);
    digitalWrite(PIN_B, HIGH);
    digitalWrite(PIN_C, HIGH);
    digitalWrite(PIN_D, HIGH);
    digitalWrite(PIN_F, HIGH);
    digitalWrite(PIN_G, HIGH);
}

void apagarSegmentos() {
  digitalWrite(PIN_A, LOW);
  digitalWrite(PIN_B, LOW);
  digitalWrite(PIN_C, LOW);
  digitalWrite(PIN_D, LOW);
  digitalWrite(PIN_E, LOW);
  digitalWrite(PIN_F, LOW);
  digitalWrite(PIN_G,LOW);
}
void lucesPorParar(){
	digitalWrite(LED_ROJA,HIGH);
  	
  	digitalWrite(LED_VERDE,LOW);
    
}

void lucesPorMovimiento(){
  digitalWrite(LED_VERDE,HIGH);
  
  digitalWrite(LED_ROJA,LOW);
  
}

void ejecutarAlFrenarEnCeroSubida(){
  			lucesPorParar();
        	apagarSegmentos();
        	pararDeSubir();
        	pararDeBajar();
          	modificarBajadaPisos();
        	frenarMontacargas();       
        	detenerMontacargas();
        	mostrarCero();
}

void ejecutarAlFrenarEnCeroBajada(){
  			lucesPorParar();
      		apagarSegmentos();
        	pararDeSubir();
        	pararDeBajar();
          	modificarSubidaPisos();
       		frenarMontacargas();
			detenerMontacargas();
          	
			mostrarCero();
}
void ejecutarAlBajarCero(){
  			lucesPorParar();
        	mostrarCero();
        	pararDeBajar();
        	delay(3000);
}

void ejecutarAlSubirCero(){
  		lucesPorMovimiento();
        modificarSubidaPisos();
        subirPisos();
        pararDeBajar();
}
void loop()
{
  switch(pisoActual)
  {
    case 0:
    	if (flagFrenar == true || digitalRead(PULSADOR_PARAR) == HIGH && flagSubida)
      	{
          	
          	ejecutarAlFrenarEnCeroSubida();

      	} else {
          if (flagFrenar == true || digitalRead(PULSADOR_PARAR) == HIGH && flagBajada) {
            ejecutarAlFrenarEnCeroBajada();
          }
        }
      if (flagBajada == true || pisoActual == 0)
      {
        	ejecutarAlBajarCero();
      } 
    if (flagSubida == true || digitalRead(PULSADOR_SUBIR) == HIGH )
      {
        ejecutarAlSubirCero();
      }
      
    	break;
    case 1:
    	if (flagFrenar == true || digitalRead(PULSADOR_PARAR) == HIGH && flagSubida)
		{
          	lucesPorParar();
      		apagarSegmentos();
        	pararDeSubir();
        	pararDeBajar();
          	modificarBajadaPisos();
        	frenarMontacargas();
			detenerMontacargas();
			mostrarUno();
		} else {
          if (flagFrenar == true || digitalRead(PULSADOR_PARAR) == HIGH && flagBajada) {
            lucesPorParar();
      		apagarSegmentos();
        	pararDeSubir();
        	pararDeBajar();
          	modificarSubidaPisos();
       		frenarMontacargas();
			detenerMontacargas();
			mostrarUno();
          }
        }
		if (flagSubida == true || digitalRead(PULSADOR_SUBIR) == HIGH)
		{
          	lucesPorMovimiento();
			apagarSegmentos();
			mostrarUno();
			
			if (flagFrenar == false){
            	subirPisos();
            	pararDeBajar();
				modificarSubidaPisos();
                
                delay(3000);
			}
		}
  		if (flagBajada == true || digitalRead(PULSADOR_BAJAR) == HIGH)
		{
          	lucesPorMovimiento();
			apagarSegmentos();
			mostrarUno();
			
			if (flagFrenar == false){
				modificarBajadaPisos();
          		bajarPisos();
            	pararDeSubir();
                
                delay(3000);
			}		
		}
      
    		break;
   case 2:
      if (flagFrenar == true || digitalRead(PULSADOR_PARAR) == HIGH && flagSubida)
		{
          	lucesPorParar();
      		apagarSegmentos();
        	pararDeSubir();
        	pararDeBajar();
          	modificarBajadaPisos();
        	frenarMontacargas();
			detenerMontacargas();
			mostrarDos();
		} else {
          if (flagFrenar == true || digitalRead(PULSADOR_PARAR) == HIGH && flagBajada) {
            lucesPorParar();
      		apagarSegmentos();
        	pararDeSubir();
        	pararDeBajar();
          	modificarSubidaPisos();
       		frenarMontacargas();
			detenerMontacargas();
          	
			mostrarDos();
          }
        }
		if (flagSubida == true || digitalRead(PULSADOR_SUBIR) == HIGH)
		{
          	lucesPorMovimiento();
			apagarSegmentos();
			mostrarDos();
			
			if (flagFrenar == false){
            	subirPisos();
            	pararDeBajar();
				modificarSubidaPisos();
                
                delay(3000);
			}
		}
  		if (flagBajada == true || digitalRead(PULSADOR_BAJAR) == HIGH)
		{
          	lucesPorMovimiento();
			apagarSegmentos();
			mostrarDos();
			
			if (flagFrenar == false){
				modificarBajadaPisos();
          		bajarPisos();
            	pararDeSubir();
                
                delay(3000);
			}		
		}		
    	
    	break;
    case 3:
    	if (flagFrenar == true || digitalRead(PULSADOR_PARAR) == HIGH && flagSubida)
		{
          	lucesPorParar();
      		apagarSegmentos();
        	pararDeSubir();
        	pararDeBajar();
          	modificarBajadaPisos();
        	frenarMontacargas();
			detenerMontacargas();
			mostrarTres();
		} else {
          if (flagFrenar == true || digitalRead(PULSADOR_PARAR) == HIGH && flagBajada) {
            lucesPorParar();
      		apagarSegmentos();
        	pararDeSubir();
        	pararDeBajar();
          	modificarSubidaPisos();
       		frenarMontacargas();
			detenerMontacargas();
          	
			mostrarNueve();
          }
        }
		if (flagSubida == true || digitalRead(PULSADOR_SUBIR) == HIGH)
		{
          	lucesPorMovimiento();
			apagarSegmentos();
			mostrarTres();
			
			if (flagFrenar == false){
            	subirPisos();
            	pararDeBajar();
				modificarSubidaPisos();
                
                delay(3000);
			}
		}
  		if (flagBajada == true || digitalRead(PULSADOR_BAJAR) == HIGH)
		{
          	lucesPorMovimiento();
			apagarSegmentos();
			mostrarTres();
			
			if (flagFrenar == false){
				modificarBajadaPisos();
          		bajarPisos();
            	pararDeSubir();
                
                delay(3000);
			}		
		}	
	
    	break;
   case 4:
    	if (flagFrenar == true || digitalRead(PULSADOR_PARAR) == HIGH && flagSubida)
		{
          	lucesPorParar();
      		apagarSegmentos();
        	pararDeSubir();
        	pararDeBajar();
          	modificarBajadaPisos();
        	frenarMontacargas();
			detenerMontacargas();
			mostrarCuatro();
		} else {
          if (flagFrenar == true || digitalRead(PULSADOR_PARAR) == HIGH && flagBajada) {
            lucesPorParar();
      		apagarSegmentos();
        	pararDeSubir();
        	pararDeBajar();
          	modificarSubidaPisos();
       		frenarMontacargas();
			detenerMontacargas();
          	
			mostrarCuatro();
          }
        }
		if (flagSubida == true || digitalRead(PULSADOR_SUBIR) == HIGH)
		{
          	lucesPorMovimiento();
			apagarSegmentos();
			mostrarCuatro();
			
			if (flagFrenar == false){
            	subirPisos();
            	pararDeBajar();
				modificarSubidaPisos();
                
                delay(3000);
			}
		}
  		if (flagBajada == true || digitalRead(PULSADOR_BAJAR) == HIGH)
		{
          	lucesPorMovimiento();
			apagarSegmentos();
			mostrarCuatro();
			
			if (flagFrenar == false){
				modificarBajadaPisos();
          		bajarPisos();
            	pararDeSubir();
                
                delay(3000);
			}		
		}
	
    	break;
   case 5:
    	if (flagFrenar == true || digitalRead(PULSADOR_PARAR) == HIGH && flagSubida)
		{
          	lucesPorParar();
      		apagarSegmentos();
        	pararDeSubir();
        	pararDeBajar();
          	modificarBajadaPisos();
        	frenarMontacargas();
			detenerMontacargas();
			mostrarCinco();
		} else {
          if (flagFrenar == true || digitalRead(PULSADOR_PARAR) == HIGH && flagBajada) {
            lucesPorParar();
      		apagarSegmentos();
        	pararDeSubir();
        	pararDeBajar();
          	modificarSubidaPisos();
       		frenarMontacargas();
			detenerMontacargas();
          	
			mostrarCinco();
          }
        }
		if (flagSubida == true || digitalRead(PULSADOR_SUBIR) == HIGH)
		{
          	lucesPorMovimiento();
			apagarSegmentos();
			mostrarCinco();
			
			if (flagFrenar == false){
            	subirPisos();
            	pararDeBajar();
				modificarSubidaPisos();
                
                delay(3000);
			}
		}
  		if (flagBajada == true || digitalRead(PULSADOR_BAJAR) == HIGH)
		{
          	lucesPorMovimiento();
			apagarSegmentos();
			mostrarCinco();
			
			if (flagFrenar == false){
				modificarBajadaPisos();
          		bajarPisos();
            	pararDeSubir();
                
                delay(3000);
			}		
		}
	
    	break;
    	
    case 6:
    	if (flagFrenar == true || digitalRead(PULSADOR_PARAR) == HIGH && flagSubida)
		{
          	lucesPorParar();
      		apagarSegmentos();
        	pararDeSubir();
        	pararDeBajar();
          	modificarBajadaPisos();
        	frenarMontacargas();
			detenerMontacargas();
			mostrarSeis();
		} else {
          if (flagFrenar == true || digitalRead(PULSADOR_PARAR) == HIGH && flagBajada) {
            lucesPorParar();
      		apagarSegmentos();
        	pararDeSubir();
        	pararDeBajar();
          	modificarSubidaPisos();
       		frenarMontacargas();
			detenerMontacargas();
          	
			mostrarSeis();
          }
        }
		if (flagSubida == true || digitalRead(PULSADOR_SUBIR) == HIGH)
		{
          	lucesPorMovimiento();
			apagarSegmentos();
			mostrarSeis();
			
			if (flagFrenar == false){
            	subirPisos();
            	pararDeBajar();
				modificarSubidaPisos();
                
                delay(3000);
			}
		}
  		if (flagBajada == true || digitalRead(PULSADOR_BAJAR) == HIGH)
		{
          	lucesPorMovimiento();
			apagarSegmentos();
			mostrarSeis();
			
			if (flagFrenar == false){
				modificarBajadaPisos();
          		bajarPisos();
            	pararDeSubir();
                
                delay(3000);
			}		
		}
		
    	break;
   case 7:
    	if (flagFrenar == true || digitalRead(PULSADOR_PARAR) == HIGH && flagSubida)
		{
          	lucesPorParar();
      		apagarSegmentos();
        	pararDeSubir();
        	pararDeBajar();
          	modificarBajadaPisos();
        	frenarMontacargas();
			detenerMontacargas();
			mostrarSiete();
		} else {
          if (flagFrenar == true || digitalRead(PULSADOR_PARAR) == HIGH && flagBajada) {
            lucesPorParar();
      		apagarSegmentos();
        	pararDeSubir();
        	pararDeBajar();
          	modificarSubidaPisos();
       		frenarMontacargas();
			detenerMontacargas();
          	
			mostrarSiete();
          }
        }
		if (flagSubida == true || digitalRead(PULSADOR_SUBIR) == HIGH)
		{
          	lucesPorMovimiento();
			apagarSegmentos();
			mostrarSiete();
			
			if (flagFrenar == false){
            	subirPisos();
            	pararDeBajar();
				modificarSubidaPisos();
                
                delay(3000);
			}
		}
  		if (flagBajada == true || digitalRead(PULSADOR_BAJAR) == HIGH)
		{
          	lucesPorMovimiento();
			apagarSegmentos();
			mostrarSiete();
			
			if (flagFrenar == false){
				modificarBajadaPisos();
          		bajarPisos();
            	pararDeSubir();
                
                delay(3000);
			}		
		}
    	break;
   case 8:
    	if (flagFrenar == true || digitalRead(PULSADOR_PARAR) == HIGH && flagSubida)
		{
          	lucesPorParar();
      		apagarSegmentos();
        	pararDeSubir();
        	pararDeBajar();
          	modificarBajadaPisos();
        	frenarMontacargas();
			detenerMontacargas();
			mostrarOcho();
		} else {
          if (flagFrenar == true || digitalRead(PULSADOR_PARAR) == HIGH && flagBajada) {
            lucesPorParar();
      		apagarSegmentos();
        	pararDeSubir();
        	pararDeBajar();
          	modificarSubidaPisos();
       		frenarMontacargas();
			detenerMontacargas();
          	
			mostrarOcho();
          }
        }
		if (flagSubida == true || digitalRead(PULSADOR_SUBIR) == HIGH)
		{
          	lucesPorMovimiento();
			apagarSegmentos();
			mostrarOcho();
			
			if (flagFrenar == false){
            	subirPisos();
            	pararDeBajar();
				modificarSubidaPisos();
                
                delay(3000);
			}
		}
  		if (flagBajada == true || digitalRead(PULSADOR_BAJAR) == HIGH)
		{
          	lucesPorMovimiento();
			apagarSegmentos();
			mostrarOcho();
			
			if (flagFrenar == false){
				modificarBajadaPisos();
          		bajarPisos();
            	pararDeSubir();
                
                delay(3000);
			}		
		}
	
    	break;
   case 9:
    	if (flagFrenar == true || digitalRead(PULSADOR_PARAR) == HIGH && flagSubida)
		{
          	lucesPorParar();
      		apagarSegmentos();
        	pararDeSubir();
        	pararDeBajar();
          	modificarBajadaPisos();
       		frenarMontacargas();
			detenerMontacargas();
          	modificarBajadaPisos();
			mostrarNueve();
        } else {
          if (flagFrenar == true || digitalRead(PULSADOR_PARAR) == HIGH && flagBajada) {
            lucesPorParar();
      		apagarSegmentos();
        	pararDeSubir();
        	pararDeBajar();
          	modificarSubidaPisos();
       		frenarMontacargas();
			detenerMontacargas();
          	
			mostrarNueve();
          }
        }
    	if (flagSubida == true || digitalRead(PULSADOR_SUBIR) == HIGH)
		{
          	lucesPorMovimiento();
			apagarSegmentos();
			mostrarNueve();
			
			if (flagFrenar == false){
            	frenarMontacargas();
				detenerMontacargas();
              	lucesPorParar();
				pararDeSubir();
                
                delay(3000);
			}
		}
  		if (flagBajada == true || digitalRead(PULSADOR_BAJAR) == HIGH)
		{
          	lucesPorMovimiento();
			apagarSegmentos();
			mostrarNueve();
			
			if (flagFrenar == false){
				modificarBajadaPisos();
				bajarPisos();
          		pararDeSubir();
              
                delay(3000);
			}		
		}
	
    	break;
  }
  
}
