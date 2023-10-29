# make: recompila só o que foi alterado e define a ordem de compilação
# mudar pingpong-contab-prio.c pro pingpong-scheduler-srtf.c 

#contrução do executavel 
ppos-exec: pingpong-contab-prio.c ppos-core-aux.c libppos_static.a
	gcc -o ppos-exec pingpong-contab-prio.c ppos-core-aux.c libppos_static.a

clean: #limpar os arquivos gerados
	rm -f ppos-exec