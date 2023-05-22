
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
#define SENSOR_LUZ_AMBIENTAL A2
#define SENSOR_INCLINACION 4
#define Trig A3
#define Eccho A4
// Se declaran las variables 
int pisoActual = 0;
bool flagSubida = true;
bool flagBajada = false;
bool flagFrenar = false;
int tiempo;
int distancia;

void setup()
{ // Se declaran los pines de salida y entrada
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
  pinMode(SENSOR_LUZ_AMBIENTAL, INPUT);
  pinMode(SENSOR_INCLINACION,INPUT);
  pinMode(Trig, OUTPUT);
  pinMode(Eccho,INPUT);
  
}

void subirPisos(){
	if (flagSubida != true)
	{	
		//Comienza a subir el montacargas por la flag
		flagSubida = true;
	}
}
void pararDeSubir(){
	if (flagSubida != false)
	{
		//Deja de subir el montacargas por la flag
		flagSubida = false;
	}
}

void bajarPisos(){
	if (flagBajada != true)
	{
      		//Comienza a bajar el montacargas por la flag
		flagBajada = true;
	}
}
void pararDeBajar(){
	if (flagBajada != false)
	{
		//Deja de bajar el montacargas por la flag
		flagBajada = false;
	}
}

void frenarMontacargas(){
	if (flagFrenar != false)
	{
		//El montacargas frena
		flagFrenar = true;
	}
  
}

void modificarSubidaPisos(){
	pisoActual = pisoActual + 1;
	//Se modifica el piso actual al subir
}

void modificarBajadaPisos() {
	//Se modifica el piso actual al bajar
	pisoActual = pisoActual - 1;
}
void mostrarCero() {
	//Se muestra al 0 por el display
  digitalWrite(PIN_A, HIGH);
  digitalWrite(PIN_B, HIGH);
  digitalWrite(PIN_C, HIGH);
  digitalWrite(PIN_D, HIGH);
  digitalWrite(PIN_E, HIGH);
  digitalWrite(PIN_F, HIGH);
}

void mostrarUno(){
	//Se muestra al 1 por el display
  	digitalWrite(PIN_B, HIGH);
  	digitalWrite(PIN_C, HIGH);
}

void mostrarDos(){
	//Se muestra al 2 por el display
  	digitalWrite(PIN_A, HIGH);
    	digitalWrite(PIN_B, HIGH);
  	digitalWrite(PIN_G, HIGH);
    	digitalWrite(PIN_E, HIGH);
    	digitalWrite(PIN_D, HIGH);
}

void mostrarTres(){
	//Se muestra al 3 por el display
    	digitalWrite(PIN_A, HIGH);
  	digitalWrite(PIN_B, HIGH);
  	digitalWrite(PIN_D, HIGH);
  	digitalWrite(PIN_C, HIGH);
  	digitalWrite(PIN_G, HIGH);
}

void mostrarCuatro(){
	//Se muestra al 4 por el display
 	digitalWrite(PIN_F, HIGH);
  	digitalWrite(PIN_G, HIGH);
    	digitalWrite(PIN_B, HIGH);
    	digitalWrite(PIN_C, HIGH);
}

void mostrarCinco(){
	//Se muestra al 5 por el display
  	digitalWrite(PIN_A, HIGH);
    	digitalWrite(PIN_F, HIGH);
    	digitalWrite(PIN_G, HIGH);
    	digitalWrite(PIN_C, HIGH);
    	digitalWrite(PIN_D, HIGH);
}

void mostrarSeis(){
	//Se muestra al 6 por el display
    	digitalWrite(PIN_A, HIGH);
    	digitalWrite(PIN_C, HIGH);
    	digitalWrite(PIN_D, HIGH);
    	digitalWrite(PIN_E, HIGH);
    	digitalWrite(PIN_F, HIGH);
    	digitalWrite(PIN_G, HIGH);
}

void mostrarSiete(){
	//Se muestra al 7 por el display
    	digitalWrite(PIN_A, HIGH);
    	digitalWrite(PIN_B, HIGH);
    	digitalWrite(PIN_C, HIGH);
    	digitalWrite(PIN_G, LOW);
}

void mostrarOcho(){
	//Se muestra al 8 por el display
    	digitalWrite(PIN_A,HIGH);
    	digitalWrite(PIN_B, HIGH);
    	digitalWrite(PIN_C, HIGH);
    	digitalWrite(PIN_D, HIGH);
    	digitalWrite(PIN_E, HIGH);
    	digitalWrite(PIN_F, HIGH);
    	digitalWrite(PIN_G, HIGH);
}

void mostrarNueve(){
	//Se muestra al 9 por el display
    	digitalWrite(PIN_A, HIGH);
    	digitalWrite(PIN_B, HIGH);
    	digitalWrite(PIN_C, HIGH);
    	digitalWrite(PIN_D, HIGH);
    	digitalWrite(PIN_F, HIGH);
    	digitalWrite(PIN_G, HIGH);
}

void apagarSegmentos() {
	//Se apagan todos los segmentos
  	digitalWrite(PIN_A, LOW);
  	digitalWrite(PIN_B, LOW);
  	digitalWrite(PIN_C, LOW);
  	digitalWrite(PIN_D, LOW);
  	digitalWrite(PIN_E, LOW);
  	digitalWrite(PIN_F, LOW);
  	digitalWrite(PIN_G,LOW);
}
void lucesPorParar(){
	//Se enciende la led roja y apaga la led verde
	digitalWrite(LED_ROJA,HIGH);
  	
  	digitalWrite(LED_VERDE,LOW);
    
}

void lucesPorMovimiento(){
	//Se enciende la led verde y apaga la led roja
  digitalWrite(LED_VERDE,HIGH);
  
  digitalWrite(LED_ROJA,LOW);
  
}

void ejecutarAlFrenarEnCeroSubida(){
	//Funciones a ejecutar su frena en 0 su sube
  		lucesPorParar();
        	apagarSegmentos();
        	pararDeSubir();
        	pararDeBajar();
          	modificarBajadaPisos();
        	frenarMontacargas(); 
        	mostrarCero();
}

void ejecutarAlFrenarEnCeroBajada(){
	//Funciones a ejecutar al frenar en 0 si baja
  		lucesPorParar();
      		apagarSegmentos();
        	pararDeSubir();
        	pararDeBajar();
          	modificarSubidaPisos();
       		frenarMontacargas();
		mostrarCero();
}
void ejecutarAlBajarCero(){
	// Funciones a ejecutar si se quiere bajar estando en 0
  		lucesPorParar();
        	mostrarCero();
        	pararDeBajar();
        	delay(3000);
}

void ejecutarAlSubirCero(){
	// Funciones a ejecutar para subir estando en 0
  	lucesPorMovimiento();
        modificarSubidaPisos();
        subirPisos();
        pararDeBajar();
}
void loop()
{
  int valorLuz = analogRead(SENSOR_LUZ_AMBIENTAL);
  int estado = digitalRead(SENSOR_INCLINACION);
  tiempo = digitalRead(Eccho);
  distancia = (tiempo * 0.034) / 2;
  if (valorLuz < 40 || estado == HIGH) {
    //Con el sensor de luz, en caso de ser de día, el montacargas no funcionará
  switch(pisoActual)
	  //En base al piso actual y al boton presionado, se ejecutarán distintas funciones.
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
		//Se frena en el 1 (Si estaba subiendo se le resta un nivel para que frene en el 1)
          		lucesPorParar();
      			apagarSegmentos();
        		pararDeSubir();
        		pararDeBajar();
          		modificarBajadaPisos();
        		frenarMontacargas();
			mostrarUno();
		} else {
          		if (flagFrenar == true || digitalRead(PULSADOR_PARAR) == HIGH && flagBajada) {
				//Se frena en el 1 (Si estaba bajando se le suma un nivel para que frene en el 1)
           			lucesPorParar();
      				apagarSegmentos();
        			pararDeSubir();
        			pararDeBajar();
          			modificarSubidaPisos();
       				frenarMontacargas();
				mostrarUno();
          		}
        	}
	if (flagSubida == true || digitalRead(PULSADOR_SUBIR) == HIGH)
	{
		//Comienza a subir desde el 1
          	lucesPorMovimiento();
		apagarSegmentos();
		mostrarUno();
			
		if (flagFrenar == false){
			//Si no quiere frenar, que sume un piso para continuar subiendo
            		subirPisos();
            		pararDeBajar();
			modificarSubidaPisos();
                	delay(3000);
			}
	}
  	if (flagBajada == true || digitalRead(PULSADOR_BAJAR) == HIGH)
	{
		//Comienza a bajar desde el 1
          	lucesPorMovimiento();
		apagarSegmentos();
		mostrarUno();
		if (flagFrenar == false){
			//Si no quiere frenar, que reste un piso para continuar bajando 
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
	      	//Se frena en el 2 (Si estaba subiendo se le resta un nivel para que frene en el 2
          	lucesPorParar();
      		apagarSegmentos();
        	pararDeSubir();
        	pararDeBajar();
          	modificarBajadaPisos();
        	frenarMontacargas();
		mostrarDos();
		} else {
          	if (flagFrenar == true || digitalRead(PULSADOR_PARAR) == HIGH && flagBajada) {
			//Se frena en el 2 (Si estaba bajando se le suma un nivel para que frene en el 2)
            		lucesPorParar();
      			apagarSegmentos();
        		pararDeSubir();
        		pararDeBajar();
          		modificarSubidaPisos();
       			frenarMontacargas();
			mostrarDos();
          	}
        }
	if (flagSubida == true || digitalRead(PULSADOR_SUBIR) == HIGH)
	{
		//Comienza a subir
          	lucesPorMovimiento();
		apagarSegmentos();
		mostrarDos();
			
		if (flagFrenar == false){
			//Si no quiere frenar, que sume un piso para seguir subiendo
            		subirPisos();
            		pararDeBajar();
			modificarSubidaPisos();
                	delay(3000);
		}
	}
  	if (flagBajada == true || digitalRead(PULSADOR_BAJAR) == HIGH)
	{
		//Comienza a bajar
          	lucesPorMovimiento();
		apagarSegmentos();
		mostrarDos();
			
		if (flagFrenar == false){
			//Si no quiere frenar, que reste un piso para seguir bajando
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
		//Se frena en el 3 (Si estaba subiendo se le resta un nivel para que frene en el 3)
          	lucesPorParar();
      		apagarSegmentos();
        	pararDeSubir();
        	pararDeBajar();
          	modificarBajadaPisos();
        	frenarMontacargas();
		mostrarTres();
		} else {
          		if (flagFrenar == true || digitalRead(PULSADOR_PARAR) == HIGH && flagBajada) {
				//Se frena en el 3 (Si estaba bajando se le suma un nivel para que frene en el 3)
            			lucesPorParar();
      				apagarSegmentos();
        			pararDeSubir();
        			pararDeBajar();
          			modificarSubidaPisos();
       				frenarMontacargas();
				mostrarTres();
          		}
        }
	if (flagSubida == true || digitalRead(PULSADOR_SUBIR) == HIGH)
	{
		//Comienza a subir
          	lucesPorMovimiento();
		apagarSegmentos();
		mostrarTres();	
		if (flagFrenar == false){
			//Si no quiere frenar, que sume un piso para seguir subiendo
            		subirPisos();
            		pararDeBajar();
			modificarSubidaPisos();
                	delay(3000);
			}
		}
  	if (flagBajada == true || digitalRead(PULSADOR_BAJAR) == HIGH)
	{
		//Comienza a bajar
          	lucesPorMovimiento();
		apagarSegmentos();
		mostrarTres();
			
		if (flagFrenar == false){
			//Si no quiere frenar, que reste un piso para seguir bajando
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
		//Se frena en el 4 (Si estaba subiendo se le resta un nivel para que frene en el 4)
          	lucesPorParar();
      		apagarSegmentos();
        	pararDeSubir();
        	pararDeBajar();
          	modificarBajadaPisos();
        	frenarMontacargas();
		mostrarCuatro();
		} else {
          	if (flagFrenar == true || digitalRead(PULSADOR_PARAR) == HIGH && flagBajada) {
			//Se frena en el 4 (Si estaba bajando se le suma un nivel para que frene en el 4)
            		lucesPorParar();
      			apagarSegmentos();
        		pararDeSubir();
        		pararDeBajar();
          		modificarSubidaPisos();
       			frenarMontacargas();
			mostrarCuatro();
          	}
        }
	if (flagSubida == true || digitalRead(PULSADOR_SUBIR) == HIGH)
	{
		//Comienza a subir
          lucesPorMovimiento();
		apagarSegmentos();
		mostrarCuatro();
			
		if (flagFrenar == false){
			//Si no quiere frenar, que sume un piso para seguir subiendo
            		subirPisos();
            		pararDeBajar();
			modificarSubidaPisos();
                	delay(3000);
		}
	}
  	if (flagBajada == true || digitalRead(PULSADOR_BAJAR) == HIGH)
	{
		//Comienza a bajar
          lucesPorMovimiento();
		apagarSegmentos();
		mostrarCuatro();
			
		if (flagFrenar == false){
			//Si no quiere frenar, que reste un piso para seguir bajando
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
		//Se frena en el 5 (Si estaba subiendo se le resta un nivel para que frene en el 5)
          	lucesPorParar();
      		apagarSegmentos();
        	pararDeSubir();
        	pararDeBajar();
          	modificarBajadaPisos();
		mostrarCinco();
		} else {
          	if (flagFrenar == true || digitalRead(PULSADOR_PARAR) == HIGH && flagBajada) {
			//Se frena en el 5 (Si estaba bajando se le suma un nivel para que frene en el 5)
            		lucesPorParar();
      			apagarSegmentos();
        		pararDeSubir();
        		pararDeBajar();
          		modificarSubidaPisos();
       			frenarMontacargas();
			mostrarCinco();
          	}
        }
	if (flagSubida == true || digitalRead(PULSADOR_SUBIR) == HIGH)
	{
		//Comienza a subir
          	lucesPorMovimiento();
		apagarSegmentos();
		mostrarCinco();
			
		if (flagFrenar == false){
			//Si no quiere frenar, que sume un piso para seguir subiendo
            		subirPisos();
            		pararDeBajar();
			modificarSubidaPisos();
                	delay(3000);
			}
	}
  	if (flagBajada == true || digitalRead(PULSADOR_BAJAR) == HIGH)
	{
		//Comienza a bajar
          	lucesPorMovimiento();
		apagarSegmentos();
		mostrarCinco();	
		if (flagFrenar == false){
			//Si no quiere frenar, que reste un piso para seguir bajando
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
		//Se frena en el 6 (Si estaba subiendo se le resta un nivel para que frene en el 6)
          	lucesPorParar();
      		apagarSegmentos();
        	pararDeSubir();
        	pararDeBajar();
          	modificarBajadaPisos();
        	frenarMontacargas();
		mostrarSeis();
		} else {
          	if (flagFrenar == true || digitalRead(PULSADOR_PARAR) == HIGH && flagBajada) {
			//Se frena en el 6 (Si estaba bajando se le suma un nivel para que frene en el 6)
            		lucesPorParar();
      			apagarSegmentos();
        		pararDeSubir();
        		pararDeBajar();
          		modificarSubidaPisos();
       			frenarMontacargas();
			mostrarSeis();
         	}
        }
	if (flagSubida == true || digitalRead(PULSADOR_SUBIR) == HIGH)
	{
		//Comienza a subir
          	lucesPorMovimiento();
		apagarSegmentos();
		mostrarSeis();
		if (flagFrenar == false){
			//Si no quiere frenar, que sume un piso para seguir subiendo
            		subirPisos();
            		pararDeBajar();
			modificarSubidaPisos();
                	delay(3000);
		}
	}
  	if (flagBajada == true || digitalRead(PULSADOR_BAJAR) == HIGH)
	{
		//Comienza a bajar
          	lucesPorMovimiento();
		apagarSegmentos();
		mostrarSeis();
		if (flagFrenar == false){
			//Si no quiere frenar, que reste un piso para seguir bajando
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
		//Se frena en el 7 (Si estaba subiendo se le resta un nivel para que frene en el 7)
          	lucesPorParar();
      		apagarSegmentos();
        	pararDeSubir();
        	pararDeBajar();
          	modificarBajadaPisos();
        	frenarMontacargas();
		mostrarSiete();
		} else {
          	if (flagFrenar == true || digitalRead(PULSADOR_PARAR) == HIGH && flagBajada) {
			//Se frena en el 7 (Si estaba bajando se le suma un nivel para que frene en el 7)
            		lucesPorParar();
      			apagarSegmentos();
        		pararDeSubir();
        		pararDeBajar();
          		modificarSubidaPisos();
       			frenarMontacargas();
			mostrarSiete();
          	}
        }
	if (flagSubida == true || digitalRead(PULSADOR_SUBIR) == HIGH)
	{
		//Comienza a subir
          	lucesPorMovimiento();
		apagarSegmentos();
		mostrarSiete();
		if (flagFrenar == false){
			//Si no quiere frenar, que sume un piso para seguir subiendo
            		subirPisos();
            		pararDeBajar();
			modificarSubidaPisos();
                	delay(3000);
		}
	}
	if (flagBajada == true || digitalRead(PULSADOR_BAJAR) == HIGH)
	{
		//Comienza a bajar
          	lucesPorMovimiento();
		apagarSegmentos();
		mostrarSiete();
		if (flagFrenar == false){
			//Si no quiere frenar, que reste un piso para seguir bajando
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
		//Se frena en el 8 (Si estaba subiendo se le resta un nivel para que frene en el 8)
          	lucesPorParar();
      		apagarSegmentos();
        	pararDeSubir();
        	pararDeBajar();
          	modificarBajadaPisos();
        	frenarMontacargas();
		mostrarOcho();
		} else {
          	if (flagFrenar == true || digitalRead(PULSADOR_PARAR) == HIGH && flagBajada) {
			//Se frena en el 9 (Si estaba bajando se le suma un nivel para que frene en el 9)
            		lucesPorParar();
      			apagarSegmentos();
        		pararDeSubir();
        		pararDeBajar();
          		modificarSubidaPisos();
       			frenarMontacargas();
			mostrarOcho();
          	}
        }
	if (flagSubida == true || digitalRead(PULSADOR_SUBIR) == HIGH)
	{
		//Comienza a subir
		lucesPorMovimiento();
		apagarSegmentos();
		mostrarOcho();
		if (flagFrenar == false){
			//Si no quiere frenar, que sume un piso para seguir subiendo
            		subirPisos();
            		pararDeBajar();
                	delay(3000);
		}
	}
	if (flagBajada == true || digitalRead(PULSADOR_BAJAR) == HIGH)
	{
		//Comienza a bajar
          	lucesPorMovimiento();
		apagarSegmentos();
		mostrarOcho();
		if (flagFrenar == false){
			//Si no quiere frenar, que reste un piso para seguir bajando
			modificarBajadaPisos();
          		bajarPisos();
            		pararDeSubir();
			delay(3000);
		}		
	}
    	break;
   case 9:
    if (distancia > 100){
      //Si el sonido detectado se encuentra lejos, 
      //que ejecute todo perfecto, sino que baje automaticamente
    	if (flagFrenar == true || digitalRead(PULSADOR_PARAR) == HIGH && flagSubida)
	{
		//Se frena en el 9 (Si estaba subiendo se le resta un nivel para que frene en el 9)
          	lucesPorParar();
      		apagarSegmentos();
        	pararDeSubir();
        	pararDeBajar();
       		frenarMontacargas();
          	modificarBajadaPisos();
		mostrarNueve();
        	} else {
          	if (flagFrenar == true || digitalRead(PULSADOR_PARAR) == HIGH && flagBajada) {
            		lucesPorParar();
      			apagarSegmentos();
        		pararDeSubir();
        		pararDeBajar();
       			frenarMontacargas();
			mostrarNueve();
          	}
        }
    	if (flagSubida == true || digitalRead(PULSADOR_SUBIR) == HIGH)
	{
		//A pesar de querer subir, se va a frenar el montacargas porque no puede seguir subiendo
		lucesPorMovimiento();
		apagarSegmentos();
		mostrarNueve();
		if (flagFrenar == false){
          
            		frenarMontacargas();
              		lucesPorParar();
					pararDeSubir();
                	delay(3000);
          
		}
	}
	if (flagBajada == true || digitalRead(PULSADOR_BAJAR) == HIGH)
	{
		//Comienza a bajar
		lucesPorMovimiento();
		apagarSegmentos();
		mostrarNueve();
		if (flagFrenar == false){
			//Si no quiere frenar, que reste un piso para seguir bajando
			modificarBajadaPisos();
			bajarPisos();
          		pararDeSubir();
                	delay(3000);
		}		
	}
    	break;
    } else {
      mostrarOcho();
      delay(1000);
      flagBajada = true;
      flagSubida = false;
      modificarBajadaPisos();
      bajarPisos();
      break;
    }
  	}
  } else {
    apagarSegmentos();
    digitalWrite(LED_ROJA,LOW);
    digitalWrite(LED_VERDE,LOW);
  }
}
