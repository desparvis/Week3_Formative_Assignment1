from setuptools import setup, Extension

module1 = Extension('cstats', sources=['cstats.c'])

setup(
    name='cstats',
    version='1.0',
    description='C extension for stats',
    ext_modules=[module1],
)