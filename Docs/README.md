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

Explicar brevemente como se espera desarrollar el trabajo de implementación.

### 2.1 Instalación

Describir brevemente las librerías utilizadas para la instalación y programas utilizados para la ejecución del código. (Agregar una sección de anexo para describir como fueron instaladas las librerías de OpenCV y la IDE utilzada para el trabajo)

### 2.2 Diseño 

Explicar los componentes (módulos o clases) utilizados para resolver el problema. Indicar arquitectura propuesta, diagrama de clases u otro artefacto que estime conveniente para explicar el diseño de su implimentación.

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

## 4. Conclusiones

# Anexos

## Anexo A: Instalación librerías OpenCV

## Anexo B: Instalación de IDE y configuración librerías OpenCV

# Referecia

Indicar los libros, páginas web, documentos, etc. Utilizados en el trabajo. Por ejemplo:

1. MONTERO, J.,Metodos matemáticos aplicados a la ganadería.3aed. Sevilla: Ediciones de la pradera,2007.
2. LVARADO,   J.   P.,¿Qué   debe   contener   un   artículo   científico?.http://www.ie.tec.ac.cr/palvarado/pmwiki/index.php/MSc/Art\%c3\%adculoCient\%c3\%adfico. Fe-cha de acceso:13/Nov/2018
