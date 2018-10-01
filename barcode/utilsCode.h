


namespace barcode {

    enum barCodeSize : int {
        DPI = 400,           //resolution
        BAR_HEIGHT_MIN = 3,  //Taille minimale
        BAR_HEIGHT_MAX = 20, //Taille Maximale
        BAR_AR_MIN = 4,      //nbr bar min
        BAR_AR_MAX = 110,    //nbr bar max
        CHARACTER_MIN = 5,
        BAR_DIST_INGROUP_MAX = 9 //Maximum distance between any grouped bar to be part of the bar group
    };
}