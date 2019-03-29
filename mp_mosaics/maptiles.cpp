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
	

	MosaicCanvas * canvas = new MosaicCanvas(theSource.getRows(),theSource.getColumns());

	 map<Point<3>,TileImage> tile_pt_map;
	 vector<Point<3>> luv_points;
	for(int i=0;i<(int)theTiles.size();i++){
		LUVAPixel p = theTiles[i].getAverageColor();
		tile_pt_map[Point<3>(p.l,p.u,p.v)] = theTiles[i];
		luv_points.push_back(Point<3>(p.l,p.u,p.v));
	}
	KDTree<3> tree(luv_points);

	for(int i=0;i<theSource.getRows();i++){
		for(int j=0;j<theSource.getColumns();j++){
			LUVAPixel p = theSource.getRegionColor(i,j);
			TileImage * image = new TileImage(tile_pt_map[tree.findNearestNeighbor(Point<3>(p.l,p.u,p.v))]);
			canvas->setTile(i,j,image);
		}
	}

    return canvas;
}

