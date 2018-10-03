#include "detectBarcode.h"
#include <exception>
#include <iostream>

DetectBarcode::DetectBarcode(cv::Mat &image) : m_image(image) {
    if (m_image.cols < 0 || m_image.rows < 0) {
        std::runtime_error("bad image");
    } else {
        m_height = (unsigned) m_image.rows;
        m_width = (unsigned) m_image.cols;
    }
}

void DetectBarcode::getDecodedObjects(std::vector<DecodedObject> &decodedObjects) {
    zbar::ImageScanner scanner;

    // Configure scanner
    scanner.set_config(zbar::ZBAR_NONE, zbar::ZBAR_CFG_ENABLE, 1);

    // Convert image to grayscale
    cv::Mat imageGray;
    cvtColor(m_image, imageGray, cv::COLOR_BGR2GRAY);

    // Wrap image data in a zbar image

    zbar::Image image(m_width, m_height, "Y800", imageGray.data, m_height*m_width);

    int n = scanner.scan(image);

    std::cout<<m_height<<" " <<n<<" "<<m_width<<std::endl;
    for(zbar::Image::SymbolIterator symbol = image.symbol_begin(); symbol != image.symbol_end(); ++symbol)
    {
        DecodedObject object;
        object.type =  symbol->get_type_name();
        object.data = symbol->get_data();
        // Print type and data

#ifdef NDEBUG
        std::cout << "Type : " << object.type << std::endl;
        std::cout << "Data : " << object.data << std::endl << std::endl;
#endif
        // Obtain location

        for (int position = 0; position < symbol->get_location_size(); ++position) {
            object.location.emplace_back(symbol->get_location_x(unsigned(position)),
                                      symbol->get_location_y(unsigned(position)));
        }
        decodedObjects.push_back(object);
    }
}

