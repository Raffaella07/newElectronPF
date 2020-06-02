import os
import string 
letter ='ABCD'


def makefile(part, let, dir):
	filename = "mini_part.%d_%s_%d.condor"%(part,let,dir)
	file = open(filename,"w")
	file.write("universe 	      = vanilla\n")
	file.write("executable            = /afs/cern.ch/work/r/ratramon/Bparking/CMSSW_10_2_15/src/macros/newElectronPF/condor/submit.sh\n")
	file.write("arguments             = ./Mini /eos/cms/store/group/phys_bphys/ratramon/BToKEE_6candidates %d_%s_%d  $(ProcId) /eos/home-r/ratramon/BToKEE_mini/%d_%s_%d_check/$(ProcId).root\n"%(part, let, dir,part, let, dir))
	file.write("output                = /afs/cern.ch/work/r/ratramon/Bparking/CMSSW_10_2_15/src/macros/newElectronPF/condor/output/MiniData6_%d%s%d.$(ProcId).out\n"%(part,let,dir))		
	file.write("error                 = /afs/cern.ch/work/r/ratramon/Bparking/CMSSW_10_2_15/src/macros/newElectronPF/condor/error/MiniData6_%d%s%d.$(ProcId).err\n"%(part,let,dir))		
	file.write("log                   = /afs/cern.ch/work/r/ratramon/Bparking/CMSSW_10_2_15/src/macros/newElectronPF/condor/log/MiniData6_%d%s%d.$(ProcId).log\n"%(part,let,dir))	
	file.write("\n")
	file.write("request_memory        = 1000 \n")
	file.write("+MaxRuntime           = 244000\n")
	file.write("queue 1000\n")
	file.close()



	

#if not os.path.isdir("/eos/home-r/ratramon/BToKEE_IPsigPF"):
#	os.mkdir("/eos/home-r/ratramon/BToKEE_IPsigPF")

for i in range(1,7):
	for j in letter:
		if j in ('A', 'B','C'):
			for k in range(0,2):
				makefile(i,j,k)
				print("%d %s %d"%(i,j,k))
				if not os.path.isdir("/eos/home-r/ratramon/BToKEE_mini/%d_%s_%d_check/"%(i,j,k)):
					os.mkdir("/eos/home-r/ratramon/BToKEE_mini/%d_%s_%d_check/"%(i,j,k))
	
		elif j == 'D' :
			for k in range(0,6):
				makefile(i,j,k)
				print("%d %s %d"%(i,j,k))
				if not os.path.isdir("/eos/home-r/ratramon/BToKEE_mini/%d_%s_%d_check/"%(i,j,k)):
					os.mkdir("/eos/home-r/ratramon/BToKEE_mini/%d_%s_%d_check/"%(i,j,k))

