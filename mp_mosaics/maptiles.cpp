/**
 * @file maptiles.cpp
 * Code for the maptiles function.
 */

#include <iostream>
#include <map>
#include "maptiles.h"
//#include "cs225/RGB_HSL.h"

using namespace std;


Point<3> convertToXYZ(LUVAPixel pixel) {
    return Point<3>( pixel.l, pixel.u, pixel.v );
}

MosaicCanvas* mapTiles(SourceImage const& theSource,
                       vector<TileImage>& theTiles)
{
    /**
     * @todo Implement this function!
     */
	if(theTiles.empty()){
		return NULL;
	}

	MosaicCanvas * canvas = new MosaicCanvas(theSource.getRows(),theSource.getColumns());

	 map<Point<3>,int> tile_pt_map;
	 vector<Point<3>> luv_points(theTiles.size());
	for(int i=0;i<(int)theTiles.size();i++){
		LUVAPixel p = theTiles[i].getAverageColor();
		tile_pt_map[Point<3>(p.l,p.u,p.v)] = i;
		luv_points[i]= Point<3>(p.l,p.u,p.v);
	}
	KDTree<3> tree(luv_points);

	for(int i=0;i<theSource.getRows();i++){
		for(int j=0;j<theSource.getColumns();j++){
			LUVAPixel p = theSource.getRegionColor(i,j);
			canvas->setTile(i,j,&theTiles[tile_pt_map[tree.findNearestNeighbor(Point<3>(p.l,p.u,p.v))]]);
		}
	}

    return canvas;
}

