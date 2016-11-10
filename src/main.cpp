/* --------------------------------------------------------------------------
    Copyright 2012 by Richard Albrecht
    richard.albrecht@rleofield.de

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
#include <string>
#include <typeinfo>
#include <string>
#include <boost/lexical_cast.hpp>
#include <float.h>
#include <vector>
#include <cmath>
#include <assert.h>
#include "t_2D_xy.h"


using namespace std;







int test_all() ;

int main() {

   int t = sizeof(double);

   int64_t a = 0;
   //int *pi = &a;

   double pch = static_cast<double>(a);

   //test_matrix();
   test_all();

   return 0;
}

