#include <Python.h>

// Function: sum_of_squares
static PyObject* sum_of_squares(PyObject* self, PyObject* args) {
    PyObject* listObj;
    if (!PyArg_ParseTuple(args, "O", &listObj))
        return NULL;

    long sum = 0;
    Py_ssize_t len = PyList_Size(listObj);

    for (Py_ssize_t i = 0; i < len; i++) {
        PyObject* item = PyList_GetItem(listObj, i);
        long value = PyLong_AsLong(item);
        sum += value * value;
    }

    return PyLong_FromLong(sum);
}

// Method table
static PyMethodDef CStatsMethods[] = {
    {"sum_of_squares", sum_of_squares, METH_VARARGS, "Compute sum of squares of a list"},
    {NULL, NULL, 0, NULL}
};

// Module definition
static struct PyModuleDef cstatsmodule = {
    PyModuleDef_HEAD_INIT,
    "cstats",        // Module name
    NULL,
    -1,
    CStatsMethods
};

// Module initialization
PyMODINIT_FUNC PyInit_cstats(void) {
    return PyModule_Create(&cstatsmodule);
}