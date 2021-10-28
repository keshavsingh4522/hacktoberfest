//===================================================================
// File:           prg0000.cpp
// Name:           Robert Fitzgerald
// Date:           09/02/05
// Description:    My First cpp program©
//===================================================================
#include <iostream.h>
#include <stdlib.h>
#include <time.h>



int main (int argc, char * argv [])
{

include "tkclient.m";
tkclient := load Tkclient Tkclient->PATH;

Resize,
Hide,
Help,
OK,
Plain:     con 1 << iota;

Appl:   con Resize | Hide;

        init:       fn();
        makedrawcontext: fn():  ref Draw->Context;
        toplevel:   fn(ctxt: ref Draw->Context, topconfig: string,
                        title: string, buts: int): (ref Tk->Toplevel, chan of string);
        onscreen:   fn(top: ref Tk->Toplevel, how: string);
        startinput: fn(top: ref Tk->Toplevel, devs: list of string);
        wmctl:      fn(top: ref Tk->Toplevel, request: string): string;
        settitle:   fn(top: ref Tk->Toplevel, name: string): string;
        handler:    fn(top: ref Tk->Toplevel, stop: chan of int);

        snarfput:   fn(buf: string);
        snarfget:   fn(): string;
	return 0;
}