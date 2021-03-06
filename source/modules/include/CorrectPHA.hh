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

// 2007-12-xx Hirokazu Odaka 
// 2009-06-22 Hirokazu Odaka 

#ifndef COMPTONSOFT_CorrectPHA_H
#define COMPTONSOFT_CorrectPHA_H 1

#include "VCSModule.hh"

namespace comptonsoft {

class CorrectPHA : public VCSModule
{
  DEFINE_ANL_MODULE(CorrectPHA, 2.1)
public:
  CorrectPHA();
  ~CorrectPHA() {}

  anl::ANLStatus mod_startup();
  anl::ANLStatus mod_init();
  anl::ANLStatus mod_ana();

private:
  std::string m_PedestalFileName;
  bool m_CMNByMedian;
};

}

#endif /* COMPTONSOFT_CorrectPHA_H */
