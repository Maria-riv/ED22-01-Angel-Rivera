![UCN](60x60-ucn-negro.png)


# Informe Técnico 
## Curso: Estructura de datos
### Detección y reidentificación de caras en secuencias de imágenes o video

**Alumnos:**

* Sebastián Angel (Encargado de la Bitácora)
* Maria Rivera (Coordinador)

## Resumen 

Describir los procesos de la implementación de un programa que detecta la entrada y salida de un grupo de personas que transitan en una zona determinada de un edificio, en ayuda a la solución de un problema solicitada por una empresa en su sistema de vigilancia. Al detectar las personas es necesario llevar un conteo de las entidades previamente detectadas y almacenadas, en conjunto a esto, la velocidad del flujo de personas que transita en cierto tiempo en el edificio. Se incluye una explicación de los elementos que ayudan en la implementación de los algoritmos a utilizar para la construcción del programa, esto en base de las librerías de OpenCV, también el detalle de la instalación de la IDE de Visual Studio Code y Cmake. Además, se incluye una descripción general del proceso funcional del programa solicitado por la empresa y de los objetivos que se han logrado para la realización exitosa de este.

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

#### Centroid Tracker
Esta clase fue creada en base al algoritmo de seguimiento de entidades a través del trackeo en base a sus centroides, o el punto medio de la "imagen" detectada.

Este algoritmo se basa en ir comparando frame por frame los centroides de las entidades detectadas, verificando cual centroide en el siguiente frame corresponde a cada una de las entidades detectadas en el frame anterior, como tambien verificar si aparecieron nuevas entidades que deben ser trackeadas.

Debido a la extension de la clase y de que todos los metodos de la misma son importantes para su correcta ejecucion se sugiere revisar su funcionamiento directamente desde los archivos del repositorio.

## 3. Resultados obtenidos
Los resultados que se obtuvieron luego de la implementacion de los metodos planteados fue la correcta detección y trackeo de entidades por medio de un registro de video (en este caso por medio de la webcam), mostrando tanto su id como su centroide en pantalla.
Se logró la implementación de un algoritmo de detección y conteo de personas que pasan por una zona en especifico, también la implementación del sistema del flujo de personas que entran y salen.

## 4. Conclusiones
Debido a diversos contratiempos sufridos durante la implementación de los algoritmos planteados y de la estructura que ibamos a seguir para el programa solo se logró la implementación exitosa de la parte de la identificacion y del trackeo de entidades (personas), ya que por diversos errores que ocurrian con lo siguiente a implementar se optó por dejar solo la parte funcional de lo conseguido para esta entrega del taller.
Los demas objetivos correspondientes a esta entrega, como tambien los requeridos para la siguiente entrega, serán cumplidos en esta misma.
# Video explicativo
* [LINK](https://drive.google.com/drive/folders/1-thzwHKsdZ_BhRwRb_jibc1GazWKDPIF?usp=sharing) VIDEO
# Anexos

## Anexo A: Instalación librerías OpenCV
* Primero se ingresa a la pagina web [OpenCV](https://opencv.org/)

![6277b466da176dc95197a5658e6ecedf](https://user-images.githubusercontent.com/82680192/175753130-dd98e37a-f043-44f0-a41c-e8704b3835a1.png)

* Se descarga y se ejecuta al finalizar la descarga

![8518f05d7d0ee7139900daa81d5faee0](https://user-images.githubusercontent.com/82680192/175753146-a0a8ebd8-4338-434c-94e6-dabeaa9de06d.png)

* Se debe editar las variables de entorno 

![139edc4fb5103a13415f997e1ea69966](https://user-images.githubusercontent.com/82680192/175753151-7769bfd2-6ff2-436c-9798-0a5ab8825689.png)

## Anexo B: Instalación de IDE y configuración librerías OpenCV
* Se descarga VS [Code](https://code.visualstudio.com/)

![4d9da5dd01d3e375c1a9e06fabf8cff0](https://user-images.githubusercontent.com/82680192/175753158-60c0a0c9-acab-457d-a820-0b31c27fb0fe.png)

* Se ejecuta e instala
* Anexo a esto se debe debe descargar [CMake](https://cmake.org/download/)

![831314f667d110a894f0f0c39683f2b6](https://user-images.githubusercontent.com/82680192/175753179-837c250c-c12a-46ab-9247-e5f06a9b25e4.png)

* Completar el proceso de instalado y luego configurarlo en VS Code

![f47dd100a7021c2b316da46e5b56c1d4](https://user-images.githubusercontent.com/82680192/175753195-c9f57f52-0d05-454f-80dc-d82e5e93c6e0.png)

* Se debe instalar primero la Extension Pack de C/C++
* Seguido de esto se debe configurar el Cmake y finalizamos con la instalación.

![06316dc86dd5679097d20d0375c2fa81](https://user-images.githubusercontent.com/82680192/175753200-f4efe65a-96ef-4f7a-acfe-fcd9a4145809.png)
![017c138525a0176b0f5c2b10ead0fc4b](https://user-images.githubusercontent.com/82680192/175753204-07f784c3-69e6-452b-8f4a-2540c82a4856.png)
# Referecia
1. IDE Visual Studio Code (https://code.visualstudio.com/).
2. Librerías para procesamiento de imágenes en C++, OpenCV (https://opencv.org/).
3. Tutoriales OpenCV y C++ (https://docs.opencv.org/master/d9/df8/tutorial root.html).
4. YouTube OpenCV y C++ (https://youtu.be/2FYm3GOonhk).
