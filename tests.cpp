//Fixed costs (cost to run quality controls, no samples)
		float fp_fixedCost = cfas + precinormU + precipathU + co2_cal 
			 + co2_norm + co2_abnorm + ise_cost + (microcuvettes * 44) 
			 + (sampleCups * 8) + alt + ast + alkp + t_bils + d_bils + ureal + ca
		     + chol + ckl + crea + ggt + glu + ldh + mg 
		     + phos + alb + tp + trig; 
			
		float lipid_fixedCost = cfas + precinormU + precipathU + precipath_lipid
			+ precinorm_lipid + cfas_lipid + (microcuvettes * 8) + (sampleCups * 7) + 
			chol + trig + hdl + ldl; 
							
		float kidney_fixedCost = cfas + precinormU + precipathU + (microcuvettes
			* 12) + (sampleCups * 4) + ureal + ca + phos + crea + alb + tp; 
		
		float liver_fixedCost = cfas + precinormU + precipathU + (microcuvettes
			* 16) + (sampleCups * 4) + alt + ast + alkp + t_bils
			+ d_bils + ldh + alb + tp; 
					
		float rodent_fixedCost = cfas + precinormU + precipathU + (microcuvettes
			* 16) + (sampleCups * 4) + alt + ast + ldh 
			+ ureal + crea + ckl + alb + tp; 
		
		float cardiac_fixedCost = cfas + precinormU + precipathU + precipath_lipid
			+ cfas_lipid + (microcuvettes * 12) + (sampleCups * 4) + 
			ckl + ldh + chol + trig + hdl + ldl; 
					
				
		float urine_fixedCost = cfas_urine + bioRad_1 + bioRad_2 + ise_cost
			+ (microcuvettes * 14) + (sampleCups * 4) + glu + tpuc + mg
			+ ca + crea + phos + ureal; 
		
		float indivTest_fixedCost = cfas + precinormU + precipathU + (microcuvettes
			* 2) + (sampleCups * 4);

		float lipid_individual_fixedCost = cfas + precinormU + precipathU
			+ cfas_lipid + precinorm_lipid 	+ precipath_lipid
			+ (microcuvettes * 2) + (sampleCups * 7);
			

		float electrolytes_fixedCost = ise_cost;
		float integra_fixedCost = (depreciation_per_year / daysUsed); //per day
		float maintanence_fixedCost = (contract_cost / daysUsed); //per day 
				

			inData << "FIXED COSTS: " << endl; 	 
			inData << "Full panel base cost: $ " << fp_fixedCost << endl; 
			inData << "Lipid panel base cost: $ " << lipid_fixedCost << endl;
			inData << "Kidney panel base cost: $ " << kidney_fixedCost << endl;
			inData << "Liver panel base cost: $ " << liver_fixedCost << endl;
			inData << "Rodent panel base cost: $ " << rodent_fixedCost << endl;
			inData << "Cardiac panel base cost: $ " << cardiac_fixedCost << endl;
			inData << "Urine panel base cost: $ " << urine_fixedCost << endl;
			inData << "Individual tests base cost: $ " << indivTest_fixedCost << endl;
			inData << "HDL/LDL individual tests base cost: $ " << lipid_individual_fixedCost
				<< endl;
			inData << "Electrolytes base cost: $ " << electrolytes_fixedCost << endl;
			inData << endl;
			inData << "Machine base cost: $ " << integra_fixedCost << endl;
			inData << "Maintanence contract base cost: $ " << maintanence_fixedCost 
				<< endl;
			inData << endl;
			
			float x = (integra_fixedCost + maintanence_fixedCost); 

			
			float fp_ff =  x + fp_fixedCost;
			float lipid_ff =  x + lipid_fixedCost;
			float kidney_ff = x + kidney_fixedCost;
			float liver_ff = x + liver_fixedCost;
			float rodent_ff = x + rodent_fixedCost;
			float cardiac_ff = x + cardiac_fixedCost;
			float urine_ff = x + urine_fixedCost;
			float indiv_ff = x + indivTest_fixedCost;
			float HDL_LDL_ff = x + lipid_individual_fixedCost;
			float electrolytes_ff = x + electrolytes_fixedCost; 
		
			inData << "FIXED COSTS (including integra cost + maintanence): " << endl;
			inData << "Full panel: $ " << fp_ff << endl;
			inData << "Lipid panel: $ " << lipid_ff << endl;
			inData << "Kidney panel: $ " << kidney_ff << endl;
			inData << "Liver panel: $ " << liver_ff << endl;
			inData << "Rodent panel: $ " << rodent_ff << endl;
			inData << "Cardiac panel: $ " << cardiac_ff << endl;
			inData << "Urine panel base cost: $ " << urine_ff << endl;
			inData << "Individual tests: $ " << indiv_ff << endl;
			inData << "HDL/LDL individual tests: $ " << HDL_LDL_ff<< endl;
			inData << "Electrolytes: $ " << electrolytes_ff << endl; 
			inData << endl;

//***************************************************************************
	//Total variable costs 
		float fp_fiveSamples = ((alt + ast + alkp + t_bils + d_bils + ureal + ca
		   + chol + ckl + crea + ggt + glu + ldh + mg 
		   + phos + alb + tp + trig) * 5) + ((microcuvettes * 21) * 5) + 
		   (sampleCups * 5) + cost_electrolytes +
		   ((wasteContainer * 22) * 5)  + activator + deproteinizer;

				float fp_varCost = fp_fiveSamples - fp_fixedCost;  
		
		float rodent_fiveSamples = ((alt + ast + ldh + ureal + crea + ckl + alb + tp + 
		   (microcuvettes * 8) + sampleCups) * 5 ) 
		   + (wasteContainer * 40) + deproteinizer + activator;
				
				float rodent_varCost = rodent_fiveSamples - rodent_fixedCost; 

		float cardiac_fiveSamples = ((ckl + ldh + chol + trig + hdl + ldl +
			 (microcuvettes * 6) + sampleCups) * 5) + 
			 + (wasteContainer * 30) + deproteinizer + activator; 

				float cardiac_varCost = cardiac_fiveSamples - cardiac_fixedCost; 

		float lipid_fiveSamples = ((chol + trig + hdl + ldl + (microcuvettes * 4)
			+ (sampleCups * 5) * 5))  + ((wasteContainer * 20) * 5) + deproteinizer + activator; 

				float lipid_varCost =  fabs (lipid_fiveSamples - lipid_fixedCost);
		
		float liver_fiveSamples = ((alt + ast + alkp + t_bils + d_bils + ldh + alb + tp
			 + (microcuvettes * 8)) * 5 ) + (wasteContainer * 40) + deproteinizer + activator; 

				float liver_varCost = liver_fiveSamples - liver_fixedCost;

		float kidney_fiveSamples = ((ureal + ca + phos + crea + alb + 
			tp + (microcuvettes * 6)) * 5) + (wasteContainer * 30) + deproteinizer + activator;

				float kidney_varCost = fabsf (kidney_fiveSamples - kidney_fixedCost);
		
		float urine_fiveSamples = ((glu + tpuc + mg + ca + crea + phos +
			ureal + (microcuvettes * 7)) * 5)
			+ (wasteContainer * 35) + ise_cost + deproteinizer;

				float urine_varCost = urine_fiveSamples - urine_fixedCost; 

		float electrolytes_fiveSamples = + ise_cost + (sampleCups * 5); 

				float electrolytes_varCost = electrolytes_fiveSamples - 
					electrolytes_fixedCost; 

		//individual tests
				
			//ggt
				float ggt_fiveSamples = (ggt + microcuvettes + sampleCups) * 5; 
					float ggt_varCost = fabsf(ggt_fiveSamples - indivTest_fixedCost); 
			//ldh
				float ldh_fiveSamples = (ldh + microcuvettes + sampleCups) *5;
					float ldh_varCost = fabsf(ldh_fiveSamples - indivTest_fixedCost);
			//ldl
				float ldl_fiveSamples = (ldl + microcuvettes + sampleCups) *5;
					float ldl_varCost = fabsf(ldl_fiveSamples - indivTest_fixedCost);
			//chol
				float chol_fiveSamples = (chol + microcuvettes + sampleCups) *5;
					float chol_varCost = fabsf(chol_fiveSamples - indivTest_fixedCost);
			//alb
				float alb_fiveSamples = (alb + microcuvettes + sampleCups) *5;
					float alb_varCost = fabsf(alb_fiveSamples - indivTest_fixedCost);
			//TP
				float tp_fiveSamples = (tp + microcuvettes + sampleCups) *5;
					float tp_varCost = fabsf(tp_fiveSamples - indivTest_fixedCost);
			//Phos 
				float phos_fiveSamples = (phos + microcuvettes + sampleCups) *5;
					float phos_varCost = fabsf(phos_fiveSamples - indivTest_fixedCost);
			//total bilirubin
				float t_bils_fiveSamples = (t_bils + microcuvettes + sampleCups) *5;
					float t_bils_varCost = fabsf(t_bils_fiveSamples - indivTest_fixedCost);
			//creatnine
				float crea_fiveSamples = (crea + microcuvettes + sampleCups) *5;
					float crea_varCost = fabsf(crea_fiveSamples - indivTest_fixedCost);
			//CO2
				float co2_fiveSamples = (co2 + microcuvettes + sampleCups) *5;
					float co2_varCost = fabsf(co2_fiveSamples - indivTest_fixedCost);
			//alkp
				float alkp_fiveSamples = (alkp + microcuvettes + sampleCups) *5;
					float alkp_varCost = fabsf(alkp_fiveSamples - indivTest_fixedCost);
			//tpuc
				float tpuc_fiveSamples = (tpuc + microcuvettes + sampleCups) *5;
					float tpuc_varCost = fabsf(tpuc_fiveSamples - indivTest_fixedCost);
			//hdl	
				float hdl_fiveSamples = (hdl + microcuvettes + sampleCups) *5;
					float hdl_varCost = fabsf(hdl_fiveSamples - indivTest_fixedCost);
			//glu
				float glu_fiveSamples = (glu + microcuvettes + sampleCups) *5;
					float glu_varCost = fabsf(glu_fiveSamples - indivTest_fixedCost);
			//ureal
				float ureal_fiveSamples = (ureal + microcuvettes + sampleCups) *5;
					float ureal_varCost = fabsf(ureal_fiveSamples - indivTest_fixedCost);
			//ckl
				float ckl_fiveSamples = (ckl + microcuvettes + sampleCups) *5;
					float ckl_varCost = fabsf(ckl_fiveSamples - indivTest_fixedCost);
			//ca
				float ca_fiveSamples = (ca + microcuvettes + sampleCups) *5;
					float ca_varCost = fabsf(ca_fiveSamples - indivTest_fixedCost);
			//direct bilirubin
				float d_bils_fiveSamples = (d_bils + microcuvettes + sampleCups) *5;
					float d_bils_varCost = fabsf(d_bils_fiveSamples - indivTest_fixedCost);
			//mg
				float mg_fiveSamples = (mg + microcuvettes + sampleCups) *5;
					float mg_varCost = fabsf(mg_fiveSamples - indivTest_fixedCost);
			//cleaner cassette 
				float cleaner_fiveSamples = (cleaner + microcuvettes + sampleCups) *5;
					float cleaner_varCost = fabsf(cleaner_fiveSamples - indivTest_fixedCost);
			//ast
				float ast_fiveSamples = (ast + microcuvettes + sampleCups) *5;
					float ast_varCost = fabsf(ast_fiveSamples - indivTest_fixedCost);
			//alt
				float alt_fiveSamples = (alt + microcuvettes + sampleCups) *5;
					float alt_varCost = fabsf(alt_fiveSamples - indivTest_fixedCost);
			//trig
				float trig_fiveSamples = (trig + microcuvettes + sampleCups) *5;
					float trig_varCost = fabsf(trig_fiveSamples - indivTest_fixedCost);

			inData << "TOTAL VARIABLE COSTS:"<< endl;
			inData << "Full panel variable costs: $ " << fp_varCost << endl;
			inData << "Rodent panel variable costs: $ " << rodent_varCost << endl;
			inData << "Cardiac panel variable costs: $ " << cardiac_varCost << endl;
			inData << "Lipid panel variable costs: $ " << lipid_varCost << endl;
			inData << "Liver panel variable costs: $ " << liver_varCost << endl;
			inData << "Kidney panel variable costs: $ " << kidney_varCost << endl;
			inData << "Urine panel variable costs: $ " <<  urine_varCost << endl;
			inData << "Electrolytes variable costs: $ " << electrolytes_varCost << endl;
			inData << endl;
			inData << "GGT: $ " << ggt_varCost << endl; 
			inData << "LDH: $ " << ldh_varCost << endl;
			inData << "LDL: $ " << ldl_varCost << endl;
			inData << "CHOL: $ " << chol_varCost << endl;
			inData << "ALB: $ " << chol_varCost << endl;
			inData << "TP: $ " << chol_varCost << endl;
			inData << "PHOS: $ " << phos_varCost << endl;
			inData << "TOTAL BILIRUBIN: $ " << t_bils_varCost << endl;
			inData << "CREA: $ " << crea_varCost << endl;
			inData << "CO2: $ " << co2_varCost << endl;
			inData << "ALKP: $ " << alkp_varCost << endl;
			inData << "TPUC: $ " << tpuc_varCost << endl;
			inData << "HDL: $ " << hdl_varCost << endl;
			inData << "GLUC: $ " << glu_varCost << endl;
			inData << "UREAL: $ " << ureal_varCost << endl;
			inData << "CKL: $ " << ckl_varCost << endl;
			inData << "CA: $ " << ca_varCost << endl;
			inData << "DIRECT BILIRUBIN: $ " << d_bils_varCost << endl;
			inData << "MG: $ " << mg_varCost << endl;
			inData << "CLEANER: $ " << cleaner_varCost << endl;
			inData << "AST: $ " << ast_varCost << endl;
			inData << "ALT: $ " << alt_varCost << endl;
			inData << "TRIG: $ " << trig_varCost << endl;
			inData << endl;
//****************************************************************************************

//****************************************************************************************
	float fp_avgTotalCost = fp_fixedCost / 5; 
	float rodent_avgTotalCost = rodent_fixedCost / 5;
	float cardiac_avgTotalCost = cardiac_fixedCost / 5;
	float lipid_avgTotalCost = lipid_fixedCost / 5;
	float liver_avgTotalCost = liver_fixedCost / 5;
	float kidney_avgTotalCost = kidney_fixedCost / 5;
	float urine_avgTotalCost = urine_fixedCost / 5; 
	float electrolytes_avgTotalCost = electrolytes_fixedCost / 5; 
	float integra_avgTotalCost = integra_fixedCost / 5; 
	float maintanence_avgTotalCost = maintanence_fixedCost / 5; 


	inData << "AVERAGE TOTAL COSTS:" << endl;
	inData << "Full panel: $ " << fp_avgTotalCost << endl;
	inData << "Rodent panel: $ " << rodent_avgTotalCost << endl;
	inData << "Cardiac panel: $ " << cardiac_avgTotalCost << endl;
	inData << "Lipid panel: $ " << lipid_avgTotalCost << endl;
	inData << "Liver panel: $ " << liver_avgTotalCost << endl;
	inData << "Kidney panel: $ " << kidney_avgTotalCost << endl;
	inData << "Urine panel: $ " << urine_avgTotalCost << endl;
	inData << "Electrolytes: $ " << electrolytes_avgTotalCost << endl;	
	inData << endl;
	inData << "Integra: $ " << integra_avgTotalCost << endl; 
	inData << "Maintanence contract: $ " << maintanence_avgTotalCost
		   << endl;
	inData << endl;
	
	float fp_avgVarCost = fp_varCost / 5;
	float rodent_avgVarCost = rodent_varCost / 5;
	float cardiac_avgVarCost = cardiac_varCost / 5;
	float lipid_avgVarCost = lipid_varCost / 5;
	float liver_avgVarCost = liver_varCost / 5;
	float kidney_avgVarCost = kidney_varCost / 5;
	float urine_avgVarCost = urine_varCost / 5; 
	float electrolytes_avgVarCost = electrolytes_varCost / 5; 

	inData << "AVERAGE VARIABLE COSTS:" << endl;
	inData << "Full panel: $ " << fp_avgVarCost << endl;
	inData << "Rodent panel: $ " << rodent_avgVarCost << endl;
	inData << "Cardiac panel: $ " << cardiac_avgVarCost << endl;
	inData << "Lipid panel: $ " << lipid_avgVarCost << endl;
	inData << "Liver panel: $ " << liver_avgVarCost << endl;
	inData << "Kidney panel: $ " << kidney_avgVarCost << endl;
	inData << "Urine panel: $ " << urine_avgVarCost << endl;
	inData << "Electrolytes: $ " << electrolytes_avgVarCost << endl;	
	inData << endl;

 //**************************************************************************
	  		 
  
	//CONTRIBUTION MARGIN 
			float fp_margin = cost_fp - fp_varCost;
			float rodent_margin = cost_rp - rodent_varCost;
			float cardiac_margin = cost_cardiac - cardiac_varCost;
			float lipid_margin = cost_lipidPanel - lipid_varCost;
			float liver_margin = cost_liverPanel - liver_varCost;
			float kidney_margin = cost_kp - kidney_varCost;
			float urine_margin = cost_up - urine_varCost;
			float electrolytes_margin = cost_electrolytes - electrolytes_varCost;

	   inData << "CONTRIBUTION MARGIN:" << endl; //price - variable costs
	   inData << "Full panel: $ " << fp_margin << endl; 
	   inData << "Rodent panel: $ " << rodent_margin << endl;
	   inData << "Cardiac panel: $ " << cardiac_margin << endl;
	   inData << "Lipid panel: $ " << lipid_margin << endl;
	   inData << "Liver panel: $ " << liver_margin << endl;
	   inData << "Kidney panel: $ " << kidney_margin << endl;
	   inData << "Urine panel: $ " << urine_margin << endl;
	   inData << "Electrolytes: $ " << electrolytes_margin << endl;
	   inData << endl;

	   inData << "BREAK-EVEN POINT: (number of tests)" << endl;
	   inData << "Full panel: " << fp_ff / fp_margin << endl;
	   inData << "Rodent panel: " << rodent_ff / rodent_margin << endl;
	   inData << "Cardiac panel: " << cardiac_ff / cardiac_margin << endl;
	   inData << "Lipid panel: " << lipid_ff / lipid_margin << endl;
	   inData << "Liver panel: " << liver_ff / liver_margin << endl;
	   inData << "Kidney panel: " << kidney_ff / kidney_margin << endl;
	   inData << "Urine panel: " << urine_ff / urine_margin << endl;
	   inData << "Electrolytes: " << electrolytes_ff / electrolytes_margin << endl;
	   inData << endl;


