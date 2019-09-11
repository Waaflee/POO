    enum TIPO_BEBIDA {
        AGUA_SABORIZADA,
        CERVEZA,
        ENERGIZANTE,
        GASOESA
    };

    enum SABOR_BEBIDA {
        LAGER,
        AMARGA,
        BLANCA,
        ANANÁ,
        MANZANA,
        PERA,
        UVA,
        COLA,
        NARANJA
    };


    class Bebida {
        TIPO_BEBIDA tipo;
        SABOR_BEBIDA sabor;
        int stock;
        int precio;
        int consultarStock();
        int consultarPecio();
        void actualizarStock(int);
        void actualizarPrecio(int);
    };