package lstd;

import java.util.List;

import burlap.behavior.singleagent.Policy;
import burlap.behavior.singleagent.vfa.ActionFeaturesQuery;
import burlap.behavior.singleagent.vfa.StateFeature;
import burlap.oomdp.core.State;
import burlap.oomdp.core.TerminalFunction;
import burlap.oomdp.singleagent.GroundedAction;
import Jama.Matrix;

public class Lstdq {

	public Matrix lstdq_l2(
			List<Sample>samples,
			RBFFeatureDatabase rbfd,
			double discount,
			Policy p,
			List<GroundedAction> actions,
			TerminalFunction tf
			) 
	{
		int k = rbfd.nRbfs * actions.size();

		System.out.println("running fast lstdq with l2 regularization");

		//L2 regularization parameter.
		//Extract the basis functions for s and s_prime.

		int m = samples.size();
		Matrix phiSA = new Matrix(k, m);
		Matrix phiSPrimeAPrime = new Matrix(k, m);

		for(int i = 0; i < m; i++)
		{
			State s = samples.get(i).getS();
			GroundedAction a = samples.get(i).getA();
			State sPrime = samples.get(i).getSprime();
			GroundedAction aPrime = p.getAction(sPrime);

			List<ActionFeaturesQuery> sfs = rbfd.getActionFeaturesSets(s, actions);
			List<ActionFeaturesQuery> sfsprime = rbfd.getActionFeaturesSets(sPrime, actions);

			if(!tf.isTerminal(s))
			{
				for(ActionFeaturesQuery afq : sfs)
				{
					if(afq.queryAction.equals(a))
					{
						for(StateFeature sf : afq.features)
						{
							phiSA.set(sf.id, i, sf.value);
						}
					}
				}
			}

			if(!tf.isTerminal(sPrime))
			{
				for(ActionFeaturesQuery afq : sfsprime)
				{
					if(afq.queryAction.equals(aPrime))
					{
						for(StateFeature sfprime : afq.features)
						{
							phiSPrimeAPrime.set(sfprime.id, i, sfprime.value);
						}
					}
				}
			}
		}

		//Initialize variables
		Matrix A = (Matrix.random(k, k)).times(0.0);
		Matrix b = (Matrix.random(k, 1)).times(0.0);

		//phiSA.getMatrix(0, k-1, c, c);
		for(int i = 0; i < m; i++)
		{
			Matrix temp_phi_sa = phiSA.getMatrix(0, k-1, i, i);   // k * 1
			Matrix temp_phi_sprimea  = phiSPrimeAPrime.getMatrix(0, k-1, i, i); // k * 1
			A.plusEquals(temp_phi_sa.times( (temp_phi_sa.minus(temp_phi_sprimea.times(discount))).transpose() ) );
			b.plusEquals(temp_phi_sa.times(samples.get(i).getR()));
		}

		Matrix w = (A.inverse()).times(b);
		return w;
	}
}
