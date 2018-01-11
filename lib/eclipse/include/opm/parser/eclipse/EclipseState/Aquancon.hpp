/*
  Copyright (C) 2017 TNO

  This file is part of the Open Porous Media project (OPM).

  OPM is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  OPM is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with OPM.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef OPM_AQUANCON_HPP
#define OPM_AQUANCON_HPP

/*
  The Aquancon is a data container object meant to hold the data from the AQUANCON keyword.
  This includes the logic for parsing as well as the associated tables. It is meant to be used by opm-grid and opm-simulators in order to
  implement the Carter Tracy analytical aquifer model in OPM Flow.
*/

#include <opm/parser/eclipse/EclipseState/Grid/EclipseGrid.hpp>
#include <opm/parser/eclipse/Parser/ParserKeywords/A.hpp>
#include <opm/parser/eclipse/Deck/Deck.hpp>
#include <opm/parser/eclipse/Deck/DeckItem.hpp>
#include <opm/parser/eclipse/Deck/DeckRecord.hpp>
#include <opm/parser/eclipse/Deck/DeckKeyword.hpp>
#include <boost/concept_check.hpp>

#include <iostream>

namespace Opm {

    class Aquancon {
        public:

            struct AquanconOutput{
                int aquiferID;
                std::vector<size_t> global_index;
                std::vector<double> face_area;
            };

            Aquancon(const EclipseGrid& grid, const Deck& deck);

            const std::vector<Aquancon::AquanconOutput>& getAquOutput() const;
    
        private:

            struct AquanconRecord{
                    // Grid cell box definition to connect aquifer
                    int i1, i2, j1, j2, k1, k2;

                    std::vector<size_t> global_index_per_record;

                    // Variables constants
                    double  influx_coeff_per_record,  //Aquifer influx coefficient
                            influx_mult_per_record;   //Aquifer influx coefficient Multiplier       
                    // Cell face to connect aquifer to        
                    std::string face_per_record;           

            };

            void logic_application(std::vector<Aquancon::AquanconOutput>& output_vector);

            void collate_function(std::vector<Aquancon::AquanconOutput>& output_vector);

            std::vector<Aquancon::AquanconOutput> m_aquoutput;

            std::vector<Aquancon::AquanconRecord> m_aqurecord;

            // Aquifer ID
            std::vector<int> m_aquiferID_per_record;
            int m_maxAquID = 0;
    };
}


#endif
