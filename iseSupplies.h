#ifndef ISESUPPLIES_H
#define ISESUPPLIES_H

#include <iosfwd>

int update_pricelist ();


double activator();
double deproteinizer();
double solution_one();
double solution_two();
double saline_diluent();
double etcher();
double ISE_direct();
double ISE_indirect();
double ISE_reference();
double sodiumElectrode();
double chlorideElectrode();
double Kelectrode();
double microcuvettes_cost();
double sampleCups_cost();
double cleaner_solution();
double wasteContainer_cost();

double techTime();

double ggt_price();
double ldl_price();
double ldh_price();
double chol_price();
double tp_price();
double alb_price();
double phos_price();
double t_bils_price ();
double crea_price();
double co2_price();
double alkp_price();
double tpuc_price();
double hdl_price();
double gluc_price();
double ureal_price();
double ckl_price();
double ca_price();
double d_bil_price();
double mg_price();
double cleaner_price();
double ast_price();
double alt_price();
double trig_price();

double wasteContainer_price();
double mc_price();
double sampeCup_price();


double co2_normal ();
double co2_abnormal ();

double cfasUrine (double);
double cfas (double);
double precipath_lipid (double ppL_cost);
double precinorm_lipid (double pnL_cost);
double precinorm_U (double pnU_cost);
double precipath_U (double ppU_cost);
double cfasLipids(double cfasL_cost);
double co2_calibrator (double cal_cost);
double bioRad1 ();
double bioRad2 ();

double activator ();
double deproteinizer ();
double solution_one () ;
double solution_two ();
double etcher();
double ISE_direct ();
double ISE_indirect ();
double ISE_reference();
double sodiumElectrode();
double chlorideElectrode();
double Kelectrode();
double microcuvettes();
double sampleCups_cost ();
double cleaner_solution();
double wasteContainer_cost();




#endif