/* --------------------------------------------------------------------------
    Copyright 2012 by Richard Albrecht
    richard.albrecht@rleofield.de
    www.rleofield.de

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 ------------------------------------------------------------------------------
*/



#include <iostream>
#include "stringhelper.h"

#include "tArea.h"
#include "t_2D_xy.h"
#include "t_3D_xyz.h"
#include "tIndexID.h"
#include "tLine.h"
#include "t_2D_Matrix.h"
#include "tObjPositionSize.h"


using namespace std;
using  rlf_minit::getScaleMatrix;
using rlf_minit::getBaseFlipMatrix;


using rlf_hstring::toString;
using rlf_hstring::split;
using rlf_hstring::clip_at_pos;
using rlf_hstring::toString;
using rlf_minit::float_m2;
using rlf_minit::float_v2;
using rlf_minit::float_xy;
using rlf_minit::double_xy;
using rlf_minit::double_xyz;
using rlf_minit::uint32_xy;
using rlf_minit::bool_xy;
using rlf_minit::tArea;


namespace {

   std::string  msgFail( string const& m, string const& testvalue, string const& correctvalue ) {
      return ( m + " ist: '" + testvalue + "'   soll: '" + correctvalue + "'" );
   }
   std::string  msgFail( string const& m, double testvalue, double correctvalue ) {
      return msgFail( m, toString( testvalue ), toString( correctvalue ) );
   }
   std::string  msgFail( string const& m, int testvalue, int correctvalue ) {
      return msgFail( m, toString( testvalue ), toString( correctvalue ) );
   }
   std::string  msgFail( string const& m, size_t testvalue, size_t correctvalue ) {
      return msgFail( m, toString( testvalue ), toString( correctvalue ) );
   }
   std::string  msgFail( string const& m, char testvalue, char correctvalue ) {
      return msgFail( m, toString( testvalue ), toString( correctvalue ) );
   }

}

void testPass( std::string const& f_,  size_t line, bool b, std::string const& msg ) {
   string f = clip_at_pos( f_, 30 ) ;
   f = toString( line ) + " " + f;

   if( b  == true ) {
      std::cout << setw( 40 ) << left << f << "  PASS  >>>> " << msg << endl;
      return;
   }

   std::cout << setw( 40 ) << left << f << "  WRONG >>>> " << msg << endl;
}

#define VERIFY(bool1,msg) testPass(__FUNCTION__,__LINE__,bool1,msg)


void TestStringstest_split_with_multiple_delimiters() {

   // 3 tokens
   std::vector<std::string> v = split( "Fuchs, du ha,st die Gans gestohlen.", ", " );
   VERIFY( v.size() == 7, "split to vector with 7 tokens" );

}

void test_float() {


   float_xy f1xy0( 1000.0f, 0.0000001f );
   float_xy f1xy1( 1000.001f, 0.00000011f ); // equal with epsilon = 1.1920929e-006
   VERIFY( f1xy0 == f1xy1, "Vergleich float mit epsilon differenz, grosser und kleiner Wert" );

   // test float/double compare
   float_xy fxy0( 1000.0f, 1000.0f );
   float_xy fxy1( 1000.001f, 1000.0f ); // equal with epsilon = 1.1920929e-006
   VERIFY( fxy0 == fxy1, "Vergleich float mit epsilon differenz, grosse Werte" );


   float_xy f2xy0( 0.0001f, 0.0001f );
   float_xy f2xy1( 0.0001000001f, 0.0001f ); // equal with epsilon = 1.1920929e-006
   VERIFY( f2xy0 == f2xy1, "Vergleich float mit epsilon differenz, kleine Werte" ) ;


}


void test_area() {
   int i = 0;
   tArea<float> a( float_xy( 2, 3 ), float_xy( 5, 5 ) );
   float_xy e = a.end();
   float_xy b = a.start();
   float_xy test( 9, 1 );
   float_xy test1 = a.clamp( test );
   VERIFY( test1 == float_xy( 6, 3 ) , "clamp to an area " );
}






void test_double() {


   // equal with epsilon =    2.2204460492503131e-015
   double_xy dxy0( 1000.0, 1000.0 );
   double_xy dxy1( 1000.000000000001, 1000.0 );

   VERIFY( dxy0 == dxy1, "Vergleich double mit epsilon differenz, grosser Wert" );


   // == with epsilon = 2.2204460492503131e-015
   double_xy d2xy0( 0.0001, 0.0001 );
   double_xy d2xy1( 0.0001000000000000001, 0.0001 );

   VERIFY( d2xy0 == d2xy1, "Vergleich double mit epsilon differenz, kleiner Wert" );



}


void test_xy_math() {

   float_xy xy0( 1.0f, 2.0f );
   float_xy xy1( 3.0f, 4.0f );
   float_xy res = xy0 + xy1;
   VERIFY( res == float_xy( 4, 6 ), "Add float_xy" );

   res = xy0 * 2.0f;
   res = xy0 - xy1;
   VERIFY( res == float_xy( -2, -2 ), "Subtract float_xy" );

   res = xy0 / xy1;
   VERIFY( res == float_xy( 0.333333333f, 0.5 ), "Div float_xy" );
   res = xy0 * xy1;
   VERIFY( res == float_xy( 3, 8 ), "Mult float_xy" );

}
void test_xy_compare() {
   float_xy xy0( 0.0f, 0.0f );
   float_xy xy1( 0.0f, 0.0f );
   VERIFY( xy0 == xy1, "Vergleich Nullwerte" );
}

void test_xyz_compare() {
   double_xyz xy0( 0.0, 0.0, 0.0 );
   double_xyz xy1( 0.0, 0.0, 0.0 );
   VERIFY( xy0 == xy1, "Vergleich Nullwerte" );
}

void test_xy_casts() {
   uint32_xy xy0( 123, 1234 );
   float_xy xy = xy0;
   VERIFY( xy == float_xy( 123.0f, 1234.0f ), "cast uint32_t -> float_xy" );

}

namespace  {
   inline float_xy to_abs( float_xy xy ) {
      return float_xy( fabs( xy.x() ), fabs( xy.y() ) );
   }
   inline float_xy toSign( bool_xy flip ) {
      float_m2 m2 = getBaseFlipMatrix( flip );
      float_xy sign = float_xy( 1.0f, 1.0f ) * m2;
      return sign;
   }
   inline float_xy toSign( bool hor, bool ver ) {
      return toSign( bool_xy( hor, ver ) );
   }

}

void test_matrix() {
   float_v2 v0( 1.0f, 2.0f );
   float_v2 v1( 3.0f, 4.0f );
   float_m2 mf2( v0, v1 );

   float a = mf2[0][0];
   float b = mf2[0][1];
   float c = mf2[1][0];
   float d = mf2[1][1];
   float_m2 mf_x ;

   float_m2 mf_s  = getScaleMatrix<float>( float_v2( 3.0f, 2.0f ) );
   float_m2 mf_s2 = getScaleMatrix<float>( float_v2( 3.0f, 6.0f ) );

   mf_s = float_m2( float_v2( 1.0f, 3.0f ), float_v2( 5.0f, 6.0f ) );  //
   mf_s2 = float_m2( float_v2( 2.0f, 1.0f ), float_v2( 7.0f, 5.0f ) ); //

   float_m2 mf_s3 = mf_s * mf_s2;

   float e = 0.0f;

}

int test_all() {
   test_xy_compare();
   test_float();
   test_double();
   test_xy_math();
   test_xy_casts();
   test_area();
   return 0;
}


