#ifndef Fecha_H
#define Fecha_H


class Fecha
{
    public:
        Fecha();
        Fecha(int, int, int);

        void ingresar();
        void mostrar();

        void setdia(int);
        int getdia();
        void setmes(int);
        int getmes();
        void setanho(int);
        int getanho();

    protected:

    private:
        int dia;
        int mes;
        int anho;
};
#endif // Fecha_H
