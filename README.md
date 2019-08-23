# MSE_21DSC

> Canal de comunicaciones para sistema digital para las comunicaciones


<a href="https://github.com/pslavkin/mse_21sdc"><img src="doc/pics/ofdm.png" title="ofdm"  width="500" height="200" alt="ofdm"></a>
---
## Progreso

- :heavy_check_mark: genero script tcl para recrear todo con lo minimo para 7010 y 7020
- :construction:     agregar
- :red_circle:       agregar

---
## Tabla de contenidos

- [tcl](#tcl)
- [cordic](#cordic)
- [Hierarchy](#hierarchy)
- [Team](#team)
- [FAQ](#faq)
- [Support](#support)
- [License](#license)
<!--
asi puedo linkear a otra seccion de otro ducumento.. por ahor dejo todo plano y vemos..
-- [linky](nuevo.md#nuevo)
-- [linkx](nuevo.md#viejo)
/!-->
---

## tcl
   explicar aca como generar y usar el tcl con rutas relativas

## cordic

   Codigo en C para calcular angulos usando tabla de puntos fijos

```ruby

int tanTable[]= { 4500,
                  2657,
                  1404,
                  713,
                  358,
                  179,
                  90,
                  45,
                  22,
                  11,
                  };
#define MAX_TABLE (sizeof(tanTable)/sizeof(tanTable[0]))


int antiClock(point_t* p,int loop)
{
   point_t pNew;
   pNew.x=p->x-(p->y>>loop);
   pNew.y=p->y+(p->x>>loop);
   *p=pNew;
   return pNew.y>0;
}
int clock(point_t* p,int loop)
{
   point_t pNew;
   pNew.x=p->x+(p->y>>loop);
   pNew.y=p->y-(p->x>>loop);
   *p=pNew;
   return pNew.y<0;
}

int findAngle(point_t p)
{
   int   i;
   int   actualAngle    = 0;
   bool  clockAntiClock = true;

   for(i=0;i<MAX_TABLE && p.y!=0;i++) {
      printf("actual point {%i,%i}\r\n",p.x,p.y);
      if(clockAntiClock==true) {
         if(clock(&p,i)) {
            clockAntiClock=false;
         }
         actualAngle+=tanTable[i];
      }
      else {
         if(antiClock(&p,i)) {
            clockAntiClock=true;
         }
         actualAngle-=tanTable[i];
      }
      printf("i=%i - clock=%i - actual=%i add/sub=%i\r\n",i,clockAntiClock,actualAngle,tanTable[i]);
      printf("new point {%i,%i}\r\n\r\n",p.x,p.y);
   }
   return actualAngle;
}
```


## Hierarchy

```ruby

.
├── bd
│   └── design_1
│       ├── design_1.bd
│       └── hdl
│           └── design_1_wrapper.vhd
├── board_store
│   ├── arty-z7-10
│   │   └── A.0
│   │       ├── board.xml
│   │       ├── part0_pins.xml
│   │       └── preset.xml
│   └── arty-z7-20
│       └── A.0
│           ├── board.xml
│           ├── part0_pins.xml
│           └── preset.xml
├── c_codes
│   ├── c
│   ├── c.c
│   ├── c.h
│   ├── CORDIC For Dummies.pdf
│   └── makefile
├── doc
│   └── pics
│       └── ofdm.png
├── FPGA_interface.sdk
│   ├── design_1_wrapper.hdf
│   └── FPGA_interface
│       └── src
│           ├── dma.c
│           ├── dma.h
│           ├── echo.c
│           ├── iic_phyreset.c
│           ├── lscript.ld
│           ├── main.c
│           ├── platform_config.c
│           ├── platform_config.h
│           ├── README.txt
│           └── Xilinx.spec
├── hdl
│   ├── Cordic_tb.vhd
│   ├── IPs
│   │   ├── rtl_system_m_axis_block_fifo
│   │   │   ├── rtl_system_m_axis_block_fifo_clocks.xdc
│   │   │   ├── rtl_system_m_axis_block_fifo.veo
│   │   │   ├── rtl_system_m_axis_block_fifo.vho
│   │   │   ├── rtl_system_m_axis_block_fifo.xci
│   │   │   ├── rtl_system_m_axis_block_fifo.xdc
│   │   │   ├── rtl_system_m_axis_block_fifo.xml
│   │   │   └── synth
│   │   │       └── rtl_system_m_axis_block_fifo.vhd
│   │   └── rtl_system_s_axis_block_fifo
│   │       ├── rtl_system_s_axis_block_fifo_clocks.xdc
│   │       ├── rtl_system_s_axis_block_fifo.veo
│   │       ├── rtl_system_s_axis_block_fifo.vho
│   │       ├── rtl_system_s_axis_block_fifo.xci
│   │       ├── rtl_system_s_axis_block_fifo.xdc
│   │       ├── rtl_system_s_axis_block_fifo.xml
│   │       └── synth
│   │           └── rtl_system_s_axis_block_fifo.vhd
│   ├── rtl_system_M_AXIS.vhd
│   ├── rtl_system_S_AXIS.vhd
│   ├── rtl_system_S_AXI.vhd
│   └── rtl_system.vhd
├── README.md
└── script.tcl

20 directories, 46 files
```

<!--

## Example (Optional)

```c
// code test

void main (void) {
   return 0;
}

```
-->

---
<!--

## Installation

- All the `code` required to get started
- Images of what it should look like

### Clone

- Clone this repo to your local machine using `https://github.com/fvcproductions/SOMEREPO`

### Setup

- If you want more syntax highlighting, format your code like this:

> update and install this package first

```shell
$ brew update
$ brew install fvcproductions
```

> now install npm and bower packages

```shell
$ npm install
$ bower install
```

- For all the possible languages that support syntax highlithing on GitHub (which is basically all of them), refer <a href="https://github.com/github/linguist/blob/master/lib/linguist/languages.yml" target="_blank">here</a>.


## Features
## Usage (Optional)
## Documentation (Optional)
## Tests (Optional)

- Going into more detail on code and technologies used
- I utilized this nifty <a href="https://github.com/adam-p/markdown-here/wiki/Markdown-Cheatsheet" target="_blank">Markdown Cheatsheet</a> for this sample `README`.



## Contributing

> To get started...

### Step 1

- **Option 1**
    - 🍴 Fork this repo!

- **Option 2**
    - 👯 Clone this repo to your local machine using `https://github.com/joanaz/HireDot2.git`

### Step 2

- **HACK AWAY!** 🔨🔨🔨

### Step 3

- 🔃 Create a new pull request using <a href="https://github.com/joanaz/HireDot2/compare/" target="_blank">`https://github.com/joanaz/HireDot2/compare/`</a>.

-->


<!--

## FAQ

- **How do I do *specifically* so and so?**
    - No problem! Just do this.


-->

## Support

Me puedes encontrar en:

   <a href="https://www.linkedin.com/in/pablo-slavkin/" target="_blank"><img src="doc/pics/linkedin.png"    title="linkedin"   width="50" height="50" alt="linkedin"></a>


## License

[![License](http://img.shields.io/:license-mit-blue.svg?style=flat-square)](http://badges.mit-license.org)

- **[MIT license](http://opensource.org/licenses/mit-license.php)**
<!-- 
- Dopyright 2019 © <a href="http://fvcproductions.com" target="_blank">FVCproductions</a>.
-->


## Team

| <a href="https://github.com/pslavkin" target="_blank">**pablo**</a>                             | <a href="https://github.com/pslavkin" target="_blank">**gonzalo**</a>                  |
| :---:                                                                                              | :---:                                                                              |
| [![pslavkin](https://avatars1.githubusercontent.com/u/8507601?s=150)](https://github.com/pslavkin) | [![gonzalo](https://avatars2.githubusercontent.com/u/37088663?s=150)](https://github.com/gonzalolavigna)  |
| <a href="https://github.com/pslavkin" target="_blank">`github.com/pslavkin`</a>                    | <a href="https://github.com/gonzalolavigna" target="_blank">`github.com/gonzalolavigna`</a>    |

<!--

## FAQ

- **How do I do *specifically* so and so?**
    - No problem! Just do this.


-->

## Support

Nos puedes encontrar en:


## License

[![License](http://img.shields.io/:license-mit-blue.svg?style=flat-square)](http://badges.mit-license.org)

- **[MIT license](http://opensource.org/licenses/mit-license.php)**
<!--
- Dopyright 2019 © <a href="http://fvcproductions.com" target="_blank">FVCproductions</a>.
-->
