![UCN](60x60-ucn-negro.png)


# Informe Técnico 
## Curso: Estructura de datos
### Detección y reidentificación de caras en secuencias de imágenes o video

**Alumnos:**

* Sebastián Angel (Encargado de la Bitácora)
* Maria Rivera (Coordinador)

## Resumen 

Descripcion de los procesos de implementacion de un programa que realiza la detección de las personas que ingresan a un edificio, además de detectarlas, realiza un conteo de aquellos que entraron y salieron, también de la velocidad del flujo de personas.
Explicación del proceso de instalación e implementacion de librerías, Cmake, OpenCV, que sirven de apoyo para la implementación los algoritmos necesarios para el funcionamiento del programa. 

## 1. Introducción

La empresa ACME desea construir un sistema de vigilancia para contar personas en una zona determinada de un edificio, en base a esta problematica se realiza el diseño e implementación de un programa que pueda detectar las personas que entran y salen del edificio. 
Para la construcción de este, es necesario la instalación y configuración de CMake y OpenCV, también la instalación de librerías importantes para la implementación de los algoritmos a utilizar. Para este programa se utilizan varios tipos de algoritmos en donde el enfoque principal es la detección de personas de forma que se puedan almacenar en estructuras de datos (Listas enlazadas simples), de forma en que se lleve el conteo de la entrada y salida de cada persona que transita en el edificio, también incluir un estudio de la velocidad del flujo de entrada y salida, además de un conteo de las personas que transitan en una zona determinada.
 
### 1.1 Descripción del problema

Detectar personas en la entrada de un edificio, identificar cada entidad para recopilar informaciones varias para lograr un conteo de las personas que salen y entran, esto debido a que la empresa necesita el balance del flujo de personas en el edificio, también se incluye la velocidad del flujo de entrada y salida.

### 1.2 Objetivos 

**Objetivo General**

Desarrollar un sistema que detecte personas, pueda almacenar entidades, contabilizar las personas que entran y salen del edificio, con el fin de llevar un balance del flujo de personas en la empresa. 

**Objetivos específicos**

1. Desarrollar un sistema de deteccion de personas en la entrada de un edificio.
2. Implementar un sistema de conteo de personas que entran y salen.
3. Desarrollar un sistema que determine la velocidad del flujo de entrada y salida de personas en un edificio.
4. Investigar el sistema de detección de objetos en OpenCV 
5. Instalar OpenCV y CMake.
6. Implementar las estructuras de datos correspondientes a utilizar
7. Implementar los algoritmos correspondientes a la deteccion, conteo y almacenamiento de entidades

### 1.3 Solución propuesta

Implementar un sistema con diversos algoritmos que contribuyan a la solucion del problema, es decir que pueda detectar y contabilizar las personas que entran y salen del edificio.

## 2. Materiales y métodos

Implementacion de los algoritmos mediante clases que permiten identificar una persona a través de los metodos incorporados en OpenCV, utilizando estructuras de datos como listas enlazadas que permiten almacenar a las entidades que corresponden a las personas y de esta forma llevar el conteo de las personas que entran y salen.
A través del método centroidTrack el cual permite seguir el rastro de la entidad encontrada, un metodo que nos sirve para diferenciar a la personas que transitan en el edificio.

### 2.1 Instalación

La librería utilizadas para la construcción del proyecto es la de OpeCV en donde su instalación se realizó por medio de la IDE Visual Studio Code, en donde por medio de distintas configuraciones, se logra la exitosa instalación.

### 2.2 Diseño 

Las clases implementadas permiten el cumplimiento de los objetivos propuestos, principalmente para la detección y conteo de las personas.
* La clase **Persona** almacena los datos de las entidades detectadas en las secuencias de video.
*  La clase **Nodo** permite almacenar el objeto Persona, en donde  el conjunto de estos nodos se almacenarán en otra clase llamada **LinkedList**.
*  La clase **LinkedList** permite guardar los datos de las entidades las cuales se almacenan en los nodos, esta lista nos permite llevar el conteo de las personas que entran y salen del edificio.
*  La clase **CentroidTracker** permite rastear las entidades detectadas, permitiendo identificar si la persona entra o sale.
* La clase **main** se encuentra implemenada con algoritmos que permiten la detección de las personas y la ejecucción del programa.

### 2.3 Implementación

Explicar brevemente algunos aspectos de implementación: Por ejemplo, detector de caras utilizado. Se pueden realizar pequeñas reseñas al código para indicar elementos importantes en el trabajo.

Por ejemplo, 

#### Detector de caras

El detector de caras utilizado fue xxx. Para utilizarlo se debe.... El código para detectar una cara en una imagen se muestra a continuación:

```c++
 1. faceCascadePath = "./haarcascade_frontalface_default.xml";
 2. faceCascade.load( faceCascadePath )
 3. std::vector<Rect> faces;
 4. faceCascade.detectMultiScale(frameGray, faces);

 5. for ( size_t i = 0; i < faces.size(); i++ )
 6. {
 7.  int x1 = faces[i].x;
 8.  int y1 = faces[i].y;
 9.  int x2 = faces[i].x + faces[i].width;
10.  int y2 = faces[i].y + faces[i].height;
11. }
```
La primera linea carga el archivo de entrenamiento... etc

## 3. Resultados obtenidos
Los resultados obtenidos en la implementación del codigo es la exitosa detección de personas y que el programa sea capaz de diferenciar cada entidad de modo de identificar una entrada y salida. También el el conteo de las personas o entidades que entran o salen.
## 4. Conclusiones
Se logró pese a las dificultades la exitosa detección de personas y determinar las personas que entran y salen, también el conteo necesario de estas con respecto a la entrada y salida. Se cumplió con el almacenamiento de la información y diferenciar entre entidades.
Faltó implementar un algoritmo para determinar la velocidad del flujo de personas debido a retrasos existentes por fallas en la instalación de la librería, errores en la implementación del algoritmo de detección de personas, etc. 
Este objetivo será cumplido para la segunda parte del proyecto la cual será el programa ya completo.
# Anexos

## Anexo A: Instalación librerías OpenCV

## Anexo B: Instalación de IDE y configuración librerías OpenCV

# Referecia
1. IDE Visual Studio Code (https://code.visualstudio.com/).
2. Librerías para procesamiento de imágenes en C++, OpenCV (https://opencv.org/).
3. Tutoriales OpenCV y C++ (https://docs.opencv.org/master/d9/df8/tutorial root.html).
4. YouTube OpenCV y C++ (https://youtu.be/2FYm3GOonhk).
