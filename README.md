## SISTEMA DE GESTION DE ESTUDIANTES Y CALIFICACIONES

# DESCRIPCION DEL PROYECTO

Aplicacion por consola desarrollada en C++ que permite gestionar los datos de estudiantes matriculados en un curso con cupo maximo de 20 estudiantes. Cada estudiante puede tener hasta 7 calificaciones. El sistema implementa operaciones CRUD (Crear, Leer, Actualizar, Eliminar) tanto para estudiantes como para calificaciones, ademas de calcular promedios individuales y del curso.

# CARACTERISTICAS PRINCIPALES

- Gestion de Estudiantes: Insertar, modificar y eliminar estudiantes con validacion de datos.
- Registro de Calificaciones: Agregar, modificar y eliminar notas (maximo 7 por estudiante).
- Calculo de Promedios: Promedio individual por estudiante y promedio general del curso.
- Validaciones: Control de cedula (10 digitos), formato de fecha (DD/MM/AAAA), limites maximos de estudiantes y notas.

# TECNOLOGIAS UTILIZADAS

- C++: Lenguaje de programacion principal
- STL (list): Estructura de datos dinamica para almacenamiento
- Standard Library: Funciones de entrada/salida, manejo de strings, fechas

# ESTRUCTURA DEL PROYECTO

- Estudiante.h: Definicion de la clase Estudiante y constantes
- Funciones.cpp: Funciones auxiliares (validaciones, utilidades)
- GestionEstudiantes.cpp: Modulo de gestion de estudiantes
- RegistroCalificaciones.cpp: Modulo de registro de notas
- PromedioEstudiante.cpp: Modulo de calculo de promedio individual
- PromedioCurso.cpp: Modulo de calculo de promedio del curso
- main.cpp: Punto de entrada y menu principal
- README.md: Documentacion del proyecto

MENU DEL SISTEMA

==============================
    === GESTOR DE PERSONAS ===
==============================
  1. Estudiantes.
  2. Registro de calificaciones.
  3. Determinar el promedio de notas de un estudiante.
  4. Determinar el promedio de notas del curso.
  0. Salir.
------------------------------
Teclee su opcion (1-4):

Opcion 1: Gestion de Estudiantes
- Listado numerado de estudiantes registrados
- Submenu con opciones: Ingresar, Modificar, Eliminar
- Validacion de cupo maximo (20 estudiantes)

Opcion 2: Registro de Calificaciones
- Busqueda de estudiante por cedula
- Gestion completa de notas (insertar, modificar, eliminar)
- Limite maximo de 7 notas por estudiante

Opcion 3: Promedio de un Estudiante
- Busqueda por cedula
- Muestra datos personales y promedio calculado

Opcion 4: Promedio del Curso
- Calcula el promedio general de todas las calificaciones
- Muestra mensaje si no hay notas registradas

# Pasos para ejecutar el codigo en Dev-C++:
1. Abrir Dev-C++.
2. Crear un nuevo proyecto: Archivo -> Nuevo -> Proyecto.
3. Seleccionar "Console Application" y elegir "C++ Project".
4. Asignar un nombre al proyecto y seleccionar la ubicacion donde se guardara.
5. Agregar los siguientes archivos al proyecto:
   - Estudiante.h
   - Funciones.cpp
   - GestionEstudiantes.cpp
   - RegistroCalificaciones.cpp
   - PromedioEstudiante.cpp
   - PromedioCurso.cpp
   - main.cpp
6. Para agregar los archivos: Proyecto -> Agregar a proyecto -> Seleccionar los archivos.
7. Compilar el proyecto: Ejecutar -> Compilar (o presionar F9).
8. Ejecutar el programa: Ejecutar -> Ejecutar (o presionar F10).

# VALIDACIONES IMPLEMENTADAS

- Cedula: Exactamente 10 digitos numericos, no duplicada
- Fecha de nacimiento: Formato DD/MM/AAAA, rangos validos (dia 1-31, mes 1-12, ano 1900-2100)
- Notas: Valores entre 0.00 y 10.00
- Limite estudiantes: Maximo 20 estudiantes
- Limite notas: Maximo 7 notas por estudiante

# AUTORES

- Monserrath: Menu + logica + resultados
- Alina: Introduccion + objetivos + teoria
- Rolando: Estructura del sistema
- Katherine: Capturas + conclusiones + formato

