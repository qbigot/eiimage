/*
 * Copyright 2011-2012 INSA Rennes
 *
 * This file is part of INSAimage.
 *
 * INSAimage is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * INSAimage is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with INSAimage.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef DPCM_H
#define DPCM_H

#include <string>
#include <GrayscaleImage.h>
#include "Quantification.h"

class DPCM
{
public:
    DPCM();
    enum Prediction {PX_EQ_A, PX_EQ_B, PX_EQ_APC, PX_EQ_Q};
    virtual ~DPCM();
    std::string execute(const imagein::GrayscaleImage *im, Prediction prediction_alg, imagein::ImageDouble **err_image, imagein::Image **recons_image, double Q = 0 );
    void setQuantification( Quantification* tquantdef );
private:
    std::string print_iloiqu();
    Quantification* quantdef;
    void codlq(int m);
    void codec(int nlq,int ier,int *icode,int *ireco);
    void set_levels();
    int iloiqu[128];
    int itcod[2048][20],itrco[2048][20],ktab[2][20];
};

#endif // DPCM_H
