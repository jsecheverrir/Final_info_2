#include "picture_management.h"

picture_management::picture_management()
{
    img = new QPixmap;
}

picture_management::~picture_management()
{
    delete img;
}

bool picture_management::load_picture(QString path)
{
    return img->load(path);
}

void picture_management::cut_picture(unsigned short x, unsigned short y, unsigned short width, unsigned short height)
{
    *img = img->copy(x,y,width,height);
}

void picture_management::scale_picture(float scale)
{
    *img = img->scaled(img->width()*scale,img->height()*scale);
}

QPixmap picture_management::get_picture()
{
    return *img;
}
