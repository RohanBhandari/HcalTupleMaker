#include "HCALPFG/HcalTupleMaker/interface/HcalTupleMaker_HcalDigis.h"
#include "FWCore/Framework/interface/Event.h"

HcalTupleMaker_HcalDigis::HcalTupleMaker_HcalDigis(const edm::ParameterSet& iConfig) :
  m_hcalDigisTag      (iConfig.getUntrackedParameter<edm::InputTag>("source")),
  m_hcalRecHitsTag    (iConfig.getUntrackedParameter<edm::InputTag>("recHits")),
  m_prefix            (iConfig.getUntrackedParameter<std::string>  ("Prefix")),
  m_suffix            (iConfig.getUntrackedParameter<std::string>  ("Suffix")),
  m_doChargeReco      (iConfig.getUntrackedParameter<bool>         ("DoChargeReco")),
  m_doEnergyReco      (iConfig.getUntrackedParameter<bool>         ("DoEnergyReco"))
{
  produces<std::vector<int>   >               ( m_prefix + "IEta"            + m_suffix );
  produces<std::vector<int>   >               ( m_prefix + "IPhi"            + m_suffix );
  produces<std::vector<int>   >               ( m_prefix + "Depth"           + m_suffix );
  produces<std::vector<int>   >               ( m_prefix + "Presamples"      + m_suffix );
  produces<std::vector<int>   >               ( m_prefix + "Size"            + m_suffix );
  produces<std::vector<int>   >               ( m_prefix + "FiberIdleOffset" + m_suffix );

  produces<std::vector<std::vector<int>   > > ( m_prefix + "DV"              + m_suffix );	     	
  produces<std::vector<std::vector<int>   > > ( m_prefix + "ER"              + m_suffix );	     	
  produces<std::vector<std::vector<int>   > > ( m_prefix + "Raw"             + m_suffix );	     	
  produces<std::vector<std::vector<int>   > > ( m_prefix + "ADC"             + m_suffix );	     	
  produces<std::vector<std::vector<float> > > ( m_prefix + "NomFC"           + m_suffix );    	
  produces<std::vector<std::vector<int>   > > ( m_prefix + "Fiber"           + m_suffix );    	
  produces<std::vector<std::vector<int>   > > ( m_prefix + "FiberChan"       + m_suffix );	
  produces<std::vector<std::vector<int>   > > ( m_prefix + "CapID"           + m_suffix );    	

  produces<std::vector<std::vector<float> > > ( m_prefix + "AllFC"           + m_suffix );    	
  produces<std::vector<std::vector<float> > > ( m_prefix + "PedFC"           + m_suffix );    	
  produces<std::vector<std::vector<float> > > ( m_prefix + "Gain"            + m_suffix );    	
  produces<std::vector<std::vector<float> > > ( m_prefix + "RCGain"          + m_suffix );    	
  produces<std::vector<std::vector<float> > > ( m_prefix + "FC"              + m_suffix );		
  produces<std::vector<std::vector<float> > > ( m_prefix + "Energy"          + m_suffix );    	

  produces<std::vector<float> >               ( m_prefix + "RecEnergy"       + m_suffix );    	
  produces<std::vector<float> >               ( m_prefix + "RecTime"         + m_suffix );      

  algo.setDoChargeReco ( m_doChargeReco );
  algo.setDoEnergyReco ( m_doEnergyReco );

}

void HcalTupleMaker_HcalDigis::loadAlgo(){
  algo.ieta            = std::auto_ptr<std::vector<int> >                 ( new std::vector<int>   ());
  algo.iphi            = std::auto_ptr<std::vector<int> >                 ( new std::vector<int>   ());
  algo.depth           = std::auto_ptr<std::vector<int> >                 ( new std::vector<int>   ());
  algo.presamples      = std::auto_ptr<std::vector<int> >                 ( new std::vector<int>   ());
  algo.size            = std::auto_ptr<std::vector<int> >                 ( new std::vector<int>   ());
  algo.fiberIdleOffset = std::auto_ptr<std::vector<int> >                 ( new std::vector<int>   ());
  algo.rec_energy      = std::auto_ptr<std::vector<float> >               ( new std::vector<float> ());  
  algo.rec_time        = std::auto_ptr<std::vector<float> >               ( new std::vector<float> ());  
  
  algo.dv 	       = std::auto_ptr<std::vector<std::vector<int  > > > ( new std::vector<std::vector<int  > > ());  
  algo.er 	       = std::auto_ptr<std::vector<std::vector<int  > > > ( new std::vector<std::vector<int  > > ());  
  algo.raw 	       = std::auto_ptr<std::vector<std::vector<int  > > > ( new std::vector<std::vector<int  > > ());  
  algo.adc 	       = std::auto_ptr<std::vector<std::vector<int  > > > ( new std::vector<std::vector<int  > > ());  
  algo.nomFC           = std::auto_ptr<std::vector<std::vector<float> > > ( new std::vector<std::vector<float> > ());  
  algo.fiber           = std::auto_ptr<std::vector<std::vector<int  > > > ( new std::vector<std::vector<int  > > ());  
  algo.fiberChan       = std::auto_ptr<std::vector<std::vector<int  > > > ( new std::vector<std::vector<int  > > ());  
  algo.capid           = std::auto_ptr<std::vector<std::vector<int  > > > ( new std::vector<std::vector<int  > > ());  
  		       
  algo.allFC           = std::auto_ptr<std::vector<std::vector<float> > > ( new std::vector<std::vector<float> > ());  
  algo.pedFC           = std::auto_ptr<std::vector<std::vector<float> > > ( new std::vector<std::vector<float> > ());  
  algo.gain            = std::auto_ptr<std::vector<std::vector<float> > > ( new std::vector<std::vector<float> > ());  
  algo.rcgain          = std::auto_ptr<std::vector<std::vector<float> > > ( new std::vector<std::vector<float> > ());  
  algo.FC 	       = std::auto_ptr<std::vector<std::vector<float> > > ( new std::vector<std::vector<float> > ());  
  algo.energy          = std::auto_ptr<std::vector<std::vector<float> > > ( new std::vector<std::vector<float> > ());  
                       

}

void HcalTupleMaker_HcalDigis::dumpAlgo( edm::Event & iEvent ){
  
  iEvent.put ( algo.ieta            , m_prefix + "IEta"            + m_suffix );
  iEvent.put ( algo.iphi            , m_prefix + "IPhi"            + m_suffix );
  iEvent.put ( algo.depth           , m_prefix + "Depth"           + m_suffix );
  iEvent.put ( algo.presamples      , m_prefix + "Presamples"      + m_suffix );
  iEvent.put ( algo.size            , m_prefix + "Size"            + m_suffix );
  iEvent.put ( algo.fiberIdleOffset , m_prefix + "FiberIdleOffset" + m_suffix );

  iEvent.put ( algo.dv 	            , m_prefix + "DV"              + m_suffix );	     	
  iEvent.put ( algo.er 	            , m_prefix + "ER"              + m_suffix );	     	
  iEvent.put ( algo.raw 	    , m_prefix + "Raw"             + m_suffix );	     	
  iEvent.put ( algo.adc 	    , m_prefix + "ADC"             + m_suffix );	     	
  iEvent.put ( algo.nomFC           , m_prefix + "NomFC"           + m_suffix );    	
  iEvent.put ( algo.fiber           , m_prefix + "Fiber"           + m_suffix );    	
  iEvent.put ( algo.fiberChan       , m_prefix + "FiberChan"       + m_suffix );	
  iEvent.put ( algo.capid           , m_prefix + "CapID"           + m_suffix );    	

  iEvent.put ( algo.allFC           , m_prefix + "AllFC"           + m_suffix );    	
  iEvent.put ( algo.pedFC           , m_prefix + "PedFC"           + m_suffix );    	
  iEvent.put ( algo.gain            , m_prefix + "Gain"            + m_suffix );    	
  iEvent.put ( algo.rcgain          , m_prefix + "RCGain"          + m_suffix );    	
  iEvent.put ( algo.FC 	            , m_prefix + "FC"              + m_suffix );		
  iEvent.put ( algo.energy          , m_prefix + "Energy"          + m_suffix );    	

  iEvent.put ( algo.rec_energy      , m_prefix + "RecEnergy"       + m_suffix );    	
  iEvent.put ( algo.rec_time        , m_prefix + "RecTime"         + m_suffix );      
  
}
