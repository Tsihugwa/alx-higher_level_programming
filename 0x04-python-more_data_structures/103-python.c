c
#include <Python.h>
#include <stdio.h>

void print_python_list(PyObject *p) {
    if (p == NULL || !PyList_Check(p)) {
        printf("[.] Invalid Python List\n");
        return;
    }

    Py_ssize_t size = PyList_Size(p);
    Py_ssize_t allocated = ((PyListObject *)p)->allocated;

    printf("[*] Python list info\n");
    printf("[*] Size of the Python List = %ld\n", size);
    printf("[*] Allocated = %ld\n", allocated);

    for (Py_ssize_t i = 0; i < size; i++) {
        PyObject *element = PyList_GetItem(p, i);

        if (PyBytes_Check(element)) {
            printf("Element %ld: bytes\n", i);
            print_python_bytes(element);
        } else if (PyLong_Check(element)) {
            printf("Element %ld: int\n", i);
        } else if (PyFloat_Check(element)) {
            printf("Element %ld: float\n", i);
        } else if (PyTuple_Check(element)) {
            printf("Element %ld: tuple\n", i);
        } else if (PyList_Check(element)) {
            printf("Element %ld: list\n", i);
        } else if (PyUnicode_Check(element)) {
            printf("Element %ld: str\n", i);
        } else {
            printf("Element %ld: unknown\n", i);
        }
    }
}

void print_python_bytes(PyObject *p) {
    if (p == NULL || !PyBytes_Check(p)) {
        printf("[.] bytes object info\n");
        printf("[ERROR] Invalid Bytes Object\n");
        return;
    }

    Py_ssize_t size = PyBytes_GET_SIZE(p);
    char *bytes = PyBytes_AS_STRING(p);

    printf("[.] bytes object info\n");
    printf(" size:
