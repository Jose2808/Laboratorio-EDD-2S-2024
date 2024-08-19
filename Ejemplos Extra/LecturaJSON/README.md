# Para usar la librería JsonCPP

1. Clonar el repositorio que contiene al lector del JSON en su proyecto

```{bash}
git clone https://github.com/open-source-parsers/jsoncpp
```

2. Ingresar a la carpeta ./jsoncpp
3. Ejecutar el siguiente comando:

```{bash}
python amalgamate.py
```
**Para ejecutar este comando necesitan tener Python 2.6 o mayor instalado**

4. Ir a la ruta **./jsoncpp/dist** y copiar en la raiz de su proyecto el archivo **jsoncpp.cpp** y la carpeta **json**

5. Incluír **"json/json.h"** en su proyecto.
