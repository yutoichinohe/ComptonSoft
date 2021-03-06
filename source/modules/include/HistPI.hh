/*************************************************************************
 *                                                                       *
 * Copyright (c) 2011 Hirokazu Odaka                                     *
 *                                                                       *
 * This program is free software: you can redistribute it and/or modify  *
 * it under the terms of the GNU General Public License as published by  *
 * the Free Software Foundation, either version 3 of the License, or     *
 * (at your option) any later version.                                   *
 *                                                                       *
 * This program is distributed in the hope that it will be useful,       *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 * GNU General Public License for more details.                          *
 *                                                                       *
 * You should have received a copy of the GNU General Public License     *
 * along with this program.  If not, see <http://www.gnu.org/licenses/>. *
 *                                                                       *
 *************************************************************************/

#ifndef COMPTONSOFT_HistPI_H
#define COMPTONSOFT_HistPI_H 1

#include "VCSModule.hh"
#include "TH1.h"

namespace comptonsoft {

class HistPI : public VCSModule
{
  DEFINE_ANL_MODULE(HistPI, 2.1);
public:
  HistPI();
  ~HistPI() {}

  anl::ANLStatus mod_his();
  anl::ANLStatus mod_ana();

private:
  std::vector<TH1*> m_hisPI;
  int m_NBin;
  double m_PIMin;
  double m_PIMax;
};

}

#endif /* COMPTONSOFT_HistPI_H */
