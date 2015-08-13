import commands
size=[8000,16000,32000,64000]
algo=['mrg_srt','qsort','insrt_srt']
order=['a','d','u']
Ln=1

cmd="printf '     Algorithm  | Input Order| Size   |Time (ms)\n' > time_log.txt"
commands.getoutput(cmd);
for n in range(len(size)):
    for o in order:
       for sorting  in algo:
           line="printf '[%02d] ' >> time_log.txt"%(Ln)
           cmd='./gen_inp %s %d | ./%s' %(o,size[n],sorting)
           commands.getoutput(line);
           res=commands.getoutput(cmd);
           print res
           commands.getoutput("printf '%s\n' >> time_log.txt"%(res));
           Ln+=1;

