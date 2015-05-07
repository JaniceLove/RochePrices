//Program to calculate costs of tests on 
//Roche Integra 400-plus

//Author: Janice Love
//Date: 8-10-2014
//Update: 5-7-2015


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

#include "iseSupplies.h" 


//function prototypes
double machineCostPerDay();
double maintenance(); 

//variables for functions 
double purchase_price = 84500; //from paperwork
		int integraLife = 10; /*simple depreciation from 
							  wikieducator.org/cost_and_financing_in
							  _open_schooling/capital_costs/depreciating_
							  capital_costs */ 
		double cost_depreciation_year = 16900; //current depreciated value-2015
		double depreciation_per_year = 4225;
		
		int daysUsed = 52 * 5; 
		int averageTestsPerDay = 5; 
int co2_no_bottles = 5;
int no_of_runs = 16;
int bioRad_no_bottles = 12; 
int bioRad_no_days = 30; 

 //maintenance contract 
		double contract_cost = 4500; 
		    //same daysUsed and average tests per day 


//cassettes:
double ggt; // (cost divide by # of tests = cost/test)
double ldh;
double ldl;
double chol;
double alb;
double tp;
double phos;
double t_bils;
double crea;
double co2;
double alkp;
double tpuc;
double hdl;
double glu;
double ureal;
double ckl;
double ca;
double d_bils;
double mg;
double cleaner;
double ast;
double alt;
double trig;

//variables pricelist
double  cfasU_cost = 304.27; 
double cfas_cost = 78.05; 		
double pp_lipid_cost = 79.49;		
double pnU_cost = 37.85; 
double ppU_cost = 38.13; 
double cfasL_cost = 59.68; 
double cal_cost = 68.86; //C02
double co2_norm_cost = 89.63; 		
double co2_abnorm_cost = 89.42;
double bio_rad_cost = 126;

double bovine_cost= 97.20;
double deproteinizer_cost = 24.34;
double soln_1_cost = 24.34; 
double soln_2_cost = 24.34; 
double saline_cost = 66.66;
double etcher_cost = 24.34;
double ISE_direct_cost = 99.26;
double ISE_indirect_cost = 172;
double reference_cost = 99.26;
double mc_cost = 490.26;
double sampleCup_cost = 53.73;
double cleanerCost = 45.91;
double waste_Container_cost = 137.72;
double na_cost =21.00;
double cl_cost = 21.00;
double k_cost = 21.00;

//cost of cassettes
double co2_cost = 14.41;
double tpuc_cost = 257.50;
double ureal_cost = 32.77;
double ckl_cost = 105.89;
double glu_cost = 52.94;
double mg_cost = 15.58;
double cleaner_cost = 45.91;
double trig_cost = 22.26;
double ldl_cost = 614.08;
double chol_cost = 27.28;
double alb_cost = 26.71;
double tp_cost = 26.71;
double phos_cost = 16.40;
double t_bils_cost = 22.26;
double crea_cost = 36.50;
double alkp_cost = 17.80;
double ca_cost = 26.71;
double d_bils_cost = 28.91;
double ast_cost = 43.09;
double alt_cost = 44.51;
double ggt_cost = 26.23;
double ldh_cost = 26.72;
double hdl_cost = 355.62; 

//no of tests per cassette
int ggt_no_tests = 400;
int ldh_no_tests = 300;		
int ldl_no_tests = 175;	
int chol_no_tests = 400;
int alb_no_tests = 300;
int tp_no_tests = 300;
int phos_no_tests = 250;
int t_bils_no_tests = 250;
int crea_no_tests = 250;
int co2_no_tests = 250;
int alkp_no_tests = 200;
int tpuc_no_tests = 150;
int hdl_no_tests = 200;
int glu_no_tests = 800;
int ureal_no_tests = 500;
int ckl_no_tests = 200;
int ca_no_tests = 300;
int d_bils_no_tests = 350;
int mg_no_tests = 175;
int cleaner_no_tests = 150;
int ast_no_tests = 500;
int alt_no_tests = 500;
int trig_no_tests = 250;



int no_of_days = 5;

int bottles = 6;

//controls:
double cfas_urine; 
double cfas_control; 		
double ppL; //precipath lipid
double precinorm; //precinorm U	
double pnL; //precinorm lipid
double ppU; //precipath U		
double cfasL; //cfas lipid	
double CO2_cal; //		
double co2_norm; //(cost-box / #-bottles) / #-runs 		
double co2_abnorm; //(cost-box / #-bottles) / #-runs 
double bioRad_1; // (cost-box / #-bottles) / 30 days 
double bioRad_2; // (cost-box / #-bottles) / 30 days 	


//ISE module and rack 
double act; //activator
double dep; // deproteinizer
double soln1; //
double soln2; //cost per bottle @ 1 bottle per week
double diluent; // saline diluent 
double etch; //etcher
double direct; //ISE direct
double indirect; //ISE indirect
double ref; //ISE reference 
double sodium; // electrode cost/day 
double chloride; // electrode cost/day
double potassium; // electrode cost/day 

//Other supplies
double sampleCups; // cost per sample cup 
double tech_time;
double mc; //microcuvettes
double waste_container; 
double cleanSoln; //cleaner solution, 1L

//Costs
double cost_fp;
double cost_rp;
double cost_kp;
double cost_up; 
double cost_cardiac;
double cost_lipidPanel;
double cost_liverPanel;
double cost_electrolytes; 
double indiv_controls;

double ise_cost;
double urineCostsControls;
double chemCostsControls;
double lipidChemControls;
double chemCostsPanels;
 
double costPerDay;



//function prototypes
double machineCostPerDay ();
double maintenance ();
void printTofile();
double wasteContainer_price();
double sampleCup_price();
double mc_price();
double co2_normal();
double co2_abnormal();
double bioRad1();
double bioRad2();


int main()
{
       ofstream myFile;
	   ofstream listFile;
	 
       myFile.open("Roche test.txt");
	   listFile.open("overhead.txt");
	 
	   listFile << fixed << setprecision(2); 
	   myFile << fixed << setprecision(2); 

		
//************************************************************************
listFile << "Purchase Price List" << std::endl;
	    listFile << "CONTROLS" << std::endl;
		listFile << "cfas urine: $ " << cfasU_cost << std::endl;
		listFile << "cfas: $" << cfas_cost << std::endl;
		listFile << "Precipath lipid: $ " << pp_lipid_cost << std::endl;
		listFile << "Precinorm U: $ " << pnU_cost << std::endl;
		listFile << "Precipath U: $" << ppU_cost << std::endl;
		listFile << "cfas lipid: $" << cfasL_cost << std::endl;
		listFile << "CO2 calibrator: $" << cal_cost << std::endl;
		listFile << "CO2 normal: $" << co2_norm_cost<< std::endl;
		listFile << "CO2 abnormal: $" << co2_abnorm_cost << std::endl;
		listFile << "Bio Rad 1: $ " << bio_rad_cost << std::endl;
		listFile << "Bio Rad 2: $ " << bio_rad_cost << std::endl;
		listFile << std::endl;
		listFile << "ISE COSTS: " << std::endl;
		listFile << "Activator: $" << bovine_cost << std::endl;
		listFile << "Deproteinizer: $ " << deproteinizer_cost << std::endl;
		listFile << "Solution One: $ " << soln_1_cost << std::endl;
		listFile << "Solution 2: $ " << soln_2_cost << std::endl;
		listFile << "Saline diluent: $ " << saline_cost << std::endl;
		listFile << "Etcher: $ " << etcher_cost << std::endl;
		listFile << "ISE direct: $ " << ISE_direct_cost
			<< std::endl;
		listFile << "ISE indirect: $ " <<ISE_indirect_cost
			<< std::endl;
		listFile << "ISE reference: $ " << reference_cost 
			<< std::endl;
		listFile<< "Sodium electrode: $ " << na_cost
			<< std::endl;
		listFile << "Chloride electrode: $ " << cl_cost
			<< std::endl;
		listFile<< "Potassium electrode: $ " << k_cost
			<< std::endl;
		listFile << std::endl;

		listFile << "MISCELLANEOUS COSTS: " << std::endl;
		listFile << "Microcuvettes: $ " << mc_cost << std::endl;
		listFile << "Sample Cups: $ " << sampleCup_cost 
				 << std::endl;
		listFile << "Cleaner solution: $ " << cleanerCost << std::endl;
		listFile << "Waste Containers: $ " << waste_Container_cost
				 << std::endl;
		listFile << std::endl;

		listFile << "CASSETTES PRICE LIST: " << std::endl;
		listFile << "GGT: $ " << ggt_cost << std::endl;
		listFile << "LDH: $ " << ldh_cost << std::endl;
		listFile << "LDL: $ " << ldl_cost << std::endl;
		listFile << "CHOL: $ " << chol_cost << std::endl;
		listFile << "ALB: $ " << alb_cost << std::endl;
		listFile << "TP: $ " << tp_cost << std::endl;
		listFile << "PHOS: $ " << phos_cost << std::endl;
		listFile << "T_BILS: $ " << t_bils_cost << std::endl;
		listFile << "CREA: $ " << crea_cost << std::endl;
		listFile << "CO2: $ " << co2_cost << std::endl;
		listFile << "ALKP: $ " << alkp_cost << std::endl;
		listFile << "TPUC: $ " << tpuc_cost << std::endl;
		listFile << "HDL: $ " << hdl_cost << std::endl;
		listFile << "GLU: $ " << glu_cost << std::endl;
		listFile << "UREAL: $ " << ureal_cost << std::endl;
		listFile << "CKL: $ " << ckl_cost << std::endl;
		listFile << "CA: $ " << ca_cost << std::endl;
		listFile << "D_BILS: $ " << d_bils_cost << std::endl;
		listFile << "MG: $ " << mg_cost << std::endl;
		listFile << "CLEANER: $ " << cleaner_cost << std::endl;
		listFile << "AST: $ " << ast_cost << std::endl;
		listFile << "ALT: $ " << alt_cost << std::endl;
		listFile << "TRIG: $ " << trig_cost << std::endl;
		listFile << std::endl;


//*************************************************************************

double labor;
labor = techTime(); 

double machine;
machine = machineCostPerDay();

double contract;
contract = maintenance();

ggt = ggt_price();
ldl = ldl_price();
ldh = ldh_price();
chol = chol_price();
tp = tp_price();
alb = alb_price();
phos = phos_price();
t_bils= t_bils_price();
crea = crea_price();
co2 = co2_price();
alkp = alkp_price();
tpuc = tpuc_price();
hdl = hdl_price();
glu = gluc_price();
ureal = ureal_price();
ckl = ckl_price();
ca = ca_price();
d_bils = d_bil_price();
mg = mg_price();
cleaner =  cleaner_price();
ast = ast_price();
alt = alt_price();
trig = trig_price();

waste_container = wasteContainer_price();
mc = mc_price();
sampleCups = sampeCup_price();



cfas_urine = cfasUrine (cfasU_cost);
cfas_control = cfas(cfas_cost);
ppL = precipath_lipid(pp_lipid_cost);
precinorm = precinorm_U(pnU_cost);
pnL = precinorm_lipid(pp_lipid_cost);
ppU = precipath_U(ppU_cost);
cfasL = cfasLipids (cfasL_cost);
CO2_cal = co2_calibrator(cal_cost);
co2_norm = co2_normal();
co2_abnorm = co2_abnormal ();
bioRad_1 = bioRad1 ();
bioRad_2 = bioRad2();

act = activator();
dep = deproteinizer();
soln1 = solution_one();
soln2 = solution_two();
etch = etcher();
direct = ISE_direct();
indirect = ISE_indirect();
ref = ISE_reference();
sodium = sodiumElectrode();
potassium = Kelectrode();
chloride = chlorideElectrode();
cleanSoln = cleaner_solution();

//*******************************************************************

//ISE module cost  
	double ise_cost = act + dep + soln1 + soln2 + diluent + etch
		+ direct + ref + indirect + sodium + chloride + potassium; 
//Urine Controls
		urineCostsControls = cfas_urine + bioRad_1 + bioRad_2 + ise_cost;
//Controls cost- per test, full panel
		chemCostsControls = cfas_control + precinorm + ppU + CO2_cal + co2_norm
			+ co2_abnorm + ise_cost; 
//Controls cost: non-full, non-lipid, non-cardiac panels
		chemCostsPanels = cfas_control + precinorm + ppU + act + dep
					      + diluent;
//Controls cost-lipid 
		lipidChemControls = cfas_control + precinorm + ppU + ppL 
						    + pnL + cfasL + act + dep + diluent;
 //cost of controls for individual tests 
		indiv_controls = cfas_control + precinorm + ppU 
						 + act + dep + diluent;
 // controls for HDL/LDL individual costs
		double lipid_individual = cfas_control + precinorm + ppU + pnL +
			 act + dep + diluent + cfasL + ppL; 

//*************************************************************************

//full panel
   cost_fp = labor + alt + ast + alkp + t_bils + d_bils + ureal + ca
		   + chol + ckl + crea + ggt + glu + ldh + mg 
		   + phos + alb + tp + trig + (mc * 21) + sampleCups
		   + chemCostsControls + costPerDay + contract + cost_electrolytes
		   + waste_container;
//Rodent panel 
	cost_rp = labor + alt + ast + ldh + ureal + crea + ckl + alb + tp + 
		   (mc * 8) + sampleCups + chemCostsPanels + costPerDay
		   + contract + waste_container;
//Cardiac panel
	cost_cardiac = labor + ckl + ldh + chol + trig + hdl + ldl +
			 (mc * 6) + sampleCups + lipidChemControls + costPerDay
			 + contract + waste_container; 
//Lipid panel 
	cost_lipidPanel = labor + chol + trig + hdl + ldl + lipidChemControls + costPerDay 
		 +  (mc * 4) + sampleCups + contract + waste_container; 
//Liver panel 
	cost_liverPanel = labor + alt + ast + alkp + t_bils + d_bils + ldh + alb + tp
			 + chemCostsPanels + (mc * 8) + costPerDay + contract + waste_container;
//Kidney panel 
    cost_kp = labor + ureal + ca + phos + crea + alb + tp + (mc * 6) 
			  + chemCostsPanels + costPerDay +  contract + waste_container;
//electrolytes 
	cost_electrolytes = costPerDay + ise_cost + sampleCups + contract + waste_container;
//Urine full panel 
	cost_up = glu + tpuc + mg + ca + crea + phos + ureal + ise_cost + costPerDay
			 + (mc * 7) + contract + waste_container;

       myFile << "Cost of full panel: " << "$ " << cost_fp << endl;
	   myFile << "Cost of rodent panel: " << "$ " << cost_rp << endl;
	   myFile << "Cost of cardiac panel: " << "$ " <<  cost_cardiac << endl; 
	   myFile << "Cost of lipid panel: " << "$ " << cost_lipidPanel << endl;
	   myFile << "Cost of liver panel: " << "$ " << cost_liverPanel << endl;
	   myFile << "Cost of kidney panel: " << "$ " << cost_kp << endl;
	   myFile << "Cost of urine full panel: " << "$ " << cost_up << endl; 
	   myFile << "Cost of electrolytes: " << "$ " << cost_electrolytes << endl; 

//*********************************************************************************

//*********************************************************************************
double ggt1 = ggt + mc + sampleCups 
			+ indiv_controls + costPerDay + waste_container + labor;
double ldh1 = ldh + mc + sampleCups 
			+ indiv_controls + costPerDay + waste_container + labor;
double ldl1 = ldl + mc + sampleCups 
			+ lipid_individual + costPerDay
			+ waste_container + labor;
double chol1 = chol + mc + sampleCups 
			+ indiv_controls + costPerDay + waste_container + labor; 
double alb1 = alb + mc + sampleCups 
			+ indiv_controls + costPerDay + waste_container + labor;
double tp1 = tp + mc + sampleCups 
			+ indiv_controls + costPerDay + waste_container + labor;
double phos1 = phos + mc + sampleCups 
			+ indiv_controls + costPerDay + waste_container + labor; 
double t_bils1 = t_bils + mc + sampleCups 
			+ indiv_controls + costPerDay + waste_container + labor; 
double crea1 = crea + mc + sampleCups 
			+ indiv_controls + costPerDay + waste_container + labor;
double co21 = co2 + mc + sampleCups 
			+ indiv_controls + costPerDay + waste_container + labor;
double alkp1 = alkp + mc + sampleCups 
			+ indiv_controls + costPerDay +  waste_container + labor;
double tpuc1 = tpuc + mc + sampleCups 
			+ indiv_controls + costPerDay + waste_container + labor; 
double hdl1 = hdl + mc + sampleCups 
			+ lipid_individual  + costPerDay
			+ waste_container + labor; 
double glu1 = glu + mc + sampleCups 
			+ indiv_controls + costPerDay + waste_container + labor;
double ureal1 = ureal + mc + sampleCups 
			+ indiv_controls + costPerDay + waste_container + labor;
double ckl1 = ckl + mc + sampleCups 
			+ indiv_controls + costPerDay + waste_container + labor;
double ca1 = ca + mc + sampleCups 
			+ indiv_controls + costPerDay +  waste_container + labor;
double d_bils1 = d_bils + mc + sampleCups 
			+ indiv_controls + costPerDay + waste_container + labor;
double mg1 = mg + mc + sampleCups 
			+ indiv_controls + costPerDay + waste_container + labor;
double cleaner1 = cleaner + mc + sampleCups 
			+ indiv_controls + costPerDay + waste_container + labor;
double ast1 = ast + mc + sampleCups 
			+ indiv_controls + costPerDay + waste_container + labor;
double alt1 = alt + mc + sampleCups 
			+ indiv_controls + costPerDay + waste_container + labor;
double trig1 = trig + mc + sampleCups 
			+ indiv_controls + costPerDay + waste_container + labor;
myFile << endl;
myFile << "CLINICAL CHEMISTRY PRICE LIST: " << endl; 
myFile << endl;
myFile << "Individual tests: " << endl;	 
myFile << "The cost of GGT is: $ " << ggt1 << endl;
myFile << "The cost of LDH is: $ " << ldh1 << endl;
myFile << "The cost of LDL is: $ " << ldl1 << endl;
myFile << "The cost of CHOL is: $ " << chol1 << endl;
myFile << "The cost of ALB is: $ " << alb1 << endl;
myFile << "The cost of TP is: $ " << tp1 << endl;
myFile << "The cost of PHOS is: $ " << phos1 << endl;
myFile << "The cost of TOTAL BILIRUBIN is: $ " << t_bils1 << endl;
myFile << "The cost of CREA is: $ " << crea1 << endl;
myFile << "The cost of CO2 is: $ " << co21 << endl;
myFile << "The cost of ALKP is: $ " << alkp1 << endl;
myFile << "The cost of TOTAL PROTEIN IN URINE is: $ " << tpuc1 << endl;
myFile << "The cost of HDL is: $ " << hdl1 << endl;
myFile << "The cost of GLUCOSE is: $ " << glu1 << endl;
myFile << "The cost of UREAL is: $ " << ureal1 << endl;
myFile << "The cost of CKL is: $ " << ckl1 << endl;
myFile << "The cost of CALCIUM is: $ " << ca1 << endl;
myFile << "The cost of DIRECT BILIRUBIN is: $ " << d_bils1 << endl;
myFile << "The cost of MG is: $ " << mg1 << endl;
myFile << "The cost of CLEANER CASSETTE is: $ " << cleaner1 << endl;
myFile << "The cost of AST is: $ " << ast1 << endl;
myFile << "The cost of ALT is: $ " << alt1 << endl;
myFile << "The cost of TRIG is: $ " << trig1 << endl;
myFile << endl;

//**********************************************************************

//non-BCM prices
	double a = costNONBCM (ggt1);
	double b = costNONBCM (ldh1);
	double c = costNONBCM (ldl1);
	double d = costNONBCM (chol1);
	double e = costNONBCM (alb1);
	double f =  costNONBCM (tp1);
	double g =  costNONBCM (phos1);
	double h =  costNONBCM (t_bils1);
	double i =  costNONBCM (crea1);
	double j =  costNONBCM (co21);
	double k =  costNONBCM (alkp1);
	double l =  costNONBCM (tpuc1);
	double m =  costNONBCM (hdl1);
	double n =  costNONBCM (glu1);
	double o =  costNONBCM (ureal1); 
	double p =  costNONBCM (ckl1);
	double q =  costNONBCM (ca1);
	double r =  costNONBCM (d_bils1);
	double s =  costNONBCM (mg1);
	double t =  costNONBCM (cleaner1);
	double u =  costNONBCM (ast1);
	double v =  costNONBCM (alt1);
	double w =  costNONBCM (trig1);

//non-academic prices 
	double aa = costOUTSIDE (ggt1);
	double bb = costOUTSIDE (ldh1);
	double cc = costOUTSIDE (ldl1);
	double dd = costOUTSIDE (chol1);
	double ee = costOUTSIDE(alb1);
	double ff =  costOUTSIDE (tp1);
	double gg =  costOUTSIDE (phos1);
	double hh =  costOUTSIDE (t_bils1);
	double ii =  costOUTSIDE(crea1);
	double jj =  costOUTSIDE (co21);
	double kk =  costOUTSIDE (alkp1);
	double ll =  costOUTSIDE (tpuc1);
	double mm =  costOUTSIDE (hdl1);
	double nn =  costOUTSIDE (glu1);
	double oo =  costOUTSIDE (ureal1); 
	double pp =  costOUTSIDE (ckl1);
	double qq =  costOUTSIDE(ca1);
	double rr =  costOUTSIDE (d_bils1);
	double ss =  costOUTSIDE(mg1);
	double tt =  costOUTSIDE(cleaner1);
	double uu =  costOUTSIDE (ast1);
	double vv =  costOUTSIDE (alt1);
	double ww=  costOUTSIDE (trig1);

	myFile << "Non-BCM (academic) prices: " << endl;
	myFile << "GGT: $" << a << endl;
	myFile << "LDH: $" << b << endl;
	myFile << "LDL: $" << c << endl;
	myFile << "CHOL: $" << d << endl;
	myFile << "ALB: $" << e << endl;
	myFile << "TP: $" << f << endl;
	myFile << "PHOS: $" << g << endl;
	myFile << "TOTAL BILIRUBIN: $" << h << endl;
	myFile << "CREA: $" << i << endl;
	myFile << "CO2: $" << j << endl;
	myFile << "ALKP: $" << k << endl;
	myFile << "TPUC: $" << l << endl;
	myFile << "HDL: $" << m << endl; 
	myFile << "GLU: $" << n << endl;
	myFile << "UREAL: $" << o << endl;
	myFile << "CKL: $" << p << endl;
	myFile << "CA: $" << q << endl;
	myFile << "DIRECT BILIRUBIN: $" << r << endl;
	myFile << "MG: $" << s << endl;
	myFile << "CLEANER: $" << t << endl;
	myFile << "AST: $" << u << endl;
	myFile << "ALT: $" << v << endl;
	myFile << "TRIG: $" << w << endl;
	myFile << endl;
	myFile << "Non-academic institution prices:" << endl;

	myFile << "GGT: $" << aa << endl;
	myFile << "LDH: $" << bb << endl;
	myFile << "LDL: $" << cc << endl;
	myFile << "CHOL: $" << dd << endl;
	myFile << "ALB: $" << ee << endl;
	myFile << "TP: $" << ff << endl;
	myFile << "PHOS: $" << gg << endl;
	myFile << "TOTAL BILIRUBIN: $" << hh << endl;
	myFile << "CREA: $" << ii << endl;
	myFile << "CO2: $" << jj << endl;
	myFile << "ALKP: $" << kk << endl;
	myFile << "TPUC: $" << ll << endl;
	myFile << "HDL: $" << mm << endl; 
	myFile << "GLU: $" << nn << endl;
	myFile << "UREAL: $" << oo << endl;
	myFile << "CKL: $" << pp << endl;
	myFile << "CA: $" << qq << endl;
	myFile << "DIRECT BILIRUBIN: $" << rr << endl;
	myFile << "MG: $" << ss << endl;
	myFile << "CLEANER: $" << tt << endl;
	myFile << "AST: $" << uu << endl;
	myFile << "ALT: $" << vv << endl;
	myFile << "TRIG: $" << ww << endl;
	myFile << "***********************************************" << endl;
	myFile << endl;

//**********************************************************************
       return 0; 

};

double machineCostPerDay()
{
	//Roche Integra 400 plus 
		
		double costPerDay = (depreciation_per_year / daysUsed) / 
			averageTestsPerDay; 

		return costPerDay;
}

double maintenance ()
{	
	double maintenance = (contract_cost / daysUsed) / 
			averageTestsPerDay; 

		return maintenance;
}
double wasteContainer_price()
{
	double a = waste_Container_cost / 1000;
	return a;
}
double mc_price()
{
	double a = mc_cost / 1000;
	return a;
}
double sampeCup_price()
{
	double a = sampleCup_cost / 1000;
	return a;
}
double co2_normal ()
{		
	double co2_norm = (co2_norm_cost / co2_no_bottles) / no_of_runs;
			//cost per run (day)
	return co2_norm;
}


double co2_abnormal () 
{	
		double co2_abnorm = (co2_abnorm_cost / co2_no_bottles) / no_of_runs; 
		return co2_abnorm;
}

double bioRad1 ()
{	
	double bioRad_1 = (bio_rad_cost / bioRad_no_bottles) / bioRad_no_days;
	return bioRad_1;
}

double bioRad2 ()
{	double bioRad_2 = (bio_rad_cost / bioRad_no_bottles) / bioRad_no_days;
		return bioRad_2;
}


double activator ()
{	 
	double bovineCostPerMl;
	int totalAmount = 500; 
	int usePerWeek = 50;
	int act_no_days = 5; 

	bovineCostPerMl = (bovine_cost / totalAmount);
	double activator_cost = (bovineCostPerMl * 50) / 5; 

	return activator_cost; 
}

double deproteinizer ()
{	
	int dep_no_bottles = 6; 
	
	double deproteinizer_price = deproteinizer_cost / dep_no_bottles / 7; 
	
	return deproteinizer_price;
}

double solution_one () 
{		
		double solution_1 = (soln_1_cost / bottles) / 15; 
		return solution_1;
}

double solution_two ()
{	
	double solution_2 = (soln_2_cost / bottles) / 15;
	return solution_2;
}

double saline_diluent ()
{	
	int saline_no_bottles = 12; //Use of half a bottle per week 
	double saline_soln = (saline_cost / saline_no_bottles) / 30; 
	return saline_soln;
}


double etcher()
{	
	int etcher_no_bottles = 6;
	double etcher = (etcher_cost / etcher_no_bottles) / 10; 
	return etcher;
}


double ISE_direct ()
{	
	double half_cost = ISE_direct_cost / 2; 
	int ISE_no_days = 5; 
	double ISE_direct = half_cost / ISE_no_days; 
	return ISE_direct;
}

double ISE_indirect ()
{	
	int indirect_no_days = 30; 
	double ISE_indirect = ISE_indirect_cost / indirect_no_days;
	return ISE_indirect;
}

double ISE_reference()
{	
	int ref_no_days = 60; 
	double ISE_reference = reference_cost / ref_no_days; 
	return ISE_reference;
}

double sodiumElectrode()
{	
	int na_no_days = 180; 
	double na_electrode = na_cost / na_no_days;
	return na_electrode;
}

double chlorideElectrode()
{	
	int cl_no_days = 90; 
	double cl_electrode = cl_cost / cl_no_days;
	return cl_electrode;
}
double Kelectrode()
{	
	int k_no_days = 180;
	double k_electrode = k_cost / k_no_days;
	return k_electrode;
}

double microcuvettes_cost ()
{	
	int no_bags = 20;
	int no_per_bag = 1000;
	double m = (mc_cost / no_bags) / no_per_bag; 
	return m;
}
double sampleCups_cost ()
{		
	int no_bag = 1000;
	double sampleCups = sampleCup_cost / no_bag; 
	return sampleCups;
}

double cleaner_solution ()
{		
	double costPerML_cleaner = cleanerCost / 1000; 
	int cleanerMLSperWeek = 500; 
	double cleaner = (cleanerMLSperWeek * costPerML_cleaner) 
			/ 5; //cost per day 
	return cleaner;
}

double wasteContainer_cost ()
{		
	int no_containers = 10; 
	double cost_per_container = waste_Container_cost / 
			no_containers; // 1 container per week, average 
	int hold = 1000; //container holds ~1000 microcuvettes
	double wasteContainer = cost_per_container / hold; // per sample
	return wasteContainer;
}

double techTime()
{
	double hourlyCost = 23.38;
	double timePerHour = 0.33; //approx. 20 minutes to load controls, samples
	double timeCost = hourlyCost * timePerHour; 
	return timeCost; 
}
double ggt_price ()
{
	double a = (ggt_cost / ggt_no_tests);
	return a;
}
double ldl_price()
{
	double a = (ldl_cost / ldl_no_tests); 
	return a; 
}
double ldh_price()
{
	double a = (ldh_cost / ldh_no_tests);
	return a; 
}

double chol_price()
{
	double a = (chol_cost / chol_no_tests);
	return a; 
}
double alb_price()
{
	double a = (alb_cost / alb_no_tests);
	return a;
}
double tp_price()
{
	double a = (tp_cost / tp_no_tests);
	return a;
}
double phos_price()
{
	double a = (phos_cost / phos_no_tests);
	return a;
}
double t_bils_price ()
{
	double a = (t_bils_cost / t_bils_no_tests);
	return a;
}
double crea_price()
{
	double a = crea_cost / crea_no_tests;
	return a;
}
double co2_price()
{
	double a = co2_cost / co2_no_tests;
	return a;
}
double alkp_price()
{
	double a = alkp_cost / alkp_no_tests;
	return a;
}
double tpuc_price()
{
	double a = tpuc_cost / tpuc_no_tests;
	return a;
}
double hdl_price()
{
	double a = hdl_cost / hdl_no_tests;
	return a;
}
double gluc_price()
{
	double a = glu_cost / glu_no_tests;
	return a;
}
double ureal_price()
{
	double a = ureal_cost / ureal_no_tests;
	return a;
}
double ckl_price()
{
	double a = ckl_cost / ckl_no_tests;
	return a;
}
double ca_price()
{
	double a = ca_cost / ca_no_tests;
	return a;
}
double d_bil_price()
{
	double a = d_bils_cost / d_bils_no_tests;
	return a; 
}
double mg_price()
{
	double a = mg_cost / mg_no_tests;
	return a; 
}
double cleaner_price()
{
	double a = cleaner_cost / cleaner_no_tests;
	return a; 
}
double ast_price()
{
	double a = ast_cost / ast_no_tests;
	return a; 
}
double alt_price()
{
	double a = alt_cost / alt_no_tests;
	return a; 
}
double trig_price()
{
	double a = trig_cost / trig_no_tests;
	return a; 
}


double cfasUrine (double cfasU_cost)
{		 
	int cfasU_no_bottles = 10;
	int cfasU_no_runs = 12;
	double cfas_urine = (cfasU_cost / cfasU_no_bottles) / cfasU_no_runs; 
			//cost per run
	return cfas_urine;
}

double cfas (double cfas_cost)
{	
	int cfas_no_bottles = 12;
	int cfas_no_days = 5; 
	double cfas = (cfas_cost / cfas_no_bottles ) / cfas_no_days;
			//cost per day 
	return cfas; 
}
double precipath_lipid (double pp_lipid_cost)
{	
	int pp_lipid_no_bottles = 4;
	int pp_lipid_no_days = 5; 
	double precipath_lipid = (pp_lipid_cost / pp_lipid_no_bottles) /
			pp_lipid_no_days;
	return precipath_lipid; //cost per day 
}
double precinorm_lipid (double pn_lipid_cost)
{	
	int pnl_noBottles = 4;
	int pnl_no_days = 5; 
	double precinorm_lipid = (pn_lipid_cost / pnl_noBottles) / 
			pnl_no_days; 

	return precinorm_lipid; //cost per day 
}
double precinorm_U (double pnU_cost)
{	
	int pnU_no_bottles = 10;
	int no_of_days = 5; 
	double precinormU = (pnU_cost / pnU_no_bottles) / no_of_days;
			//cost/day
	return precinormU;
}
double precipath_U (double ppU_cost)
{	
	int ppU_no_bottles = 10;
		//same number of days 
		
	double precipathU = (ppU_cost / ppU_no_bottles) / no_of_days;
	return precipathU; //cost/day
}
double cfasLipids (double cfasL_cost)
{	
	int cfasL_no_bottles = 10;
		//same number of days
	double cfas_lipid = (cfasL_cost / cfasL_no_bottles) / no_of_days;
			//cost per day
	return cfas_lipid;
}

double co2_calibrator (double cal_cost)
{	
	int co2_no_bottles = 5;
	int no_of_runs = 16;
	double co2_cal = (cal_cost / co2_no_bottles) / no_of_runs;
			//cost/run (day)
	return co2_cal;
}