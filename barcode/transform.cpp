



namespace barcode{
    void getCenterPoint(const std::vector< cv::RotatedRect > & vecRotRect , std::vector<cv::Point> & center) {
        //Converts an array of RotatedRect's to an array of their center points.
        for(int i = 0; i < vecRotRect.size(); i++){
            vecPts[i] = cv::Point(vecRotRect[i].center.x, vecRotRect[i].center.y);
        }
        return vecPts;
    }


}