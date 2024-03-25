#ifndef PICTURE_MANAGEMENT_H
#define PICTURE_MANAGEMENT_H

#include <QPixmap>

class picture_management
{
public:
    picture_management();
    ~picture_management();
    bool load_picture(QString path);
    void cut_picture(unsigned short x, unsigned short y, unsigned short width, unsigned short height);
    void scale_picture(float scale);
    QPixmap get_picture();

private:
    QPixmap *img;
};

#endif // PICTURE_MANAGEMENT_H
