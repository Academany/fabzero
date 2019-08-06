# Electronics design

- [Electronics design](#electronics-design)
  - [The Introduction](#the-introduction)
    - [Schematics](#schematics)
    - [PCB Layout](#pcb-layout)
      - [Eagle Specific](#eagle-specific)
      - [KiCad specific](#kicad-specific)
  - [Drawing your circuits](#drawing-your-circuits)
  - [Resources](#resources)
    - [Eagle](#eagle)
    - [KiCad](#kicad)

Welcome to the amazing world of electronics design. We will learn tools and acquire some skills to be able to design our own circuit boards, which together with the skills of Electronics Production will allow us to fabricate our own circuit boards. And this is not only super cool, but also a huge step in digital fabrication. There are several ways you can create your electronics design. These are just some that we will cover:

- Drawing your circuit boards by hand. With the help of a template
- Using [KiCad](http://kicad-pcb.org/) or Eagle (though, we do not recommend this)

Remember that in any case, what you will obtain is a black and white `.png` image for [fab modules](http://fabmodules.org) or [mods](http://mods.cba.mit.edu).

## The Introduction

### Schematics

- Using the datasheets and the reference circuits to create the schematic diagram of the circuit
- Library management 
  - Finding and adding component libraries 
  - Customizing/editing or adding symbols/footprints (this is optional)

### PCB Layout
There is a saying in the community, the PCB layout design is 90% proper component placement and 10% routing.


- Best practices
    - Component placement 
    - Keyboard shortcuts
- Positioning sensitive components (like decoupling capacitors)    
- Following manufacturer guidelines 
- DRC rules
  - Minimum trace width
  - Minimum drill size 
  - Minimum separation for different signals 
  - Minimum via drill size
  - Minimum via diameter
- Double sided PCB design considerations 
- Double sided PCB cut-out
- Layers and uses
- PNG Outputs for Fabbing in FabLab

#### Eagle Specific
- Autorouter
- [Selective autorouter / Quick Route](https://www.youtube.com/watch?v=l3gWqGKVU4Q)

#### KiCad specific 

- Schematic symbol to footprint association 
- Interactive routing options 

## Drawing your circuits

Hands-on activity.

## Resources 

This [Autodesk blog](https://www.autodesk.com/products/eagle/blog/) has a lot of resources related to PCB design.


### Eagle

Even if you are not planning to use Eagle you **still want to know the basics of Eagle** because you will find many designs out there using this format. You have to learn how to create the Schematic Design first and then the Design Layout. These are two half an hour tutorials:

- [Video Tutorial 1: Schematic Design](https://www.youtube.com/watch?v=1AXwjZoyNno)
- [Video Tutorial 2: Board Design](https://www.youtube.com/watch?v=CCTs0mNXY24)
- [Autodesk blog: Component placement](https://www.autodesk.com/products/eagle/blog/pcb-layout-basics-component-placement/)
- [Autodesk blog: Routing and autorouting](https://www.autodesk.com/products/eagle/blog/routing-autorouting-pcb-layout-basics-2/)
- [Autodesk blog: DRC](https://www.autodesk.com/products/eagle/blog/design-rule-check-pcb-layout-basics-3/)
- [Autodesk blog: Are you better than Autorouter](https://www.autodesk.com/products/eagle/blog/are-you-better-than-the-autorouter/)


### KiCad

KiCad is an FOSS tool, since 2015 CERN stared contributing heavily to the development of the tool and it's getting more and more powerful and popular with the hobbyists. Recently Autdesk bought Eagle and they made it into a subscription model software, and started integrating it with other CAD tools of their own. They also made internet connectivity mandatory (every two weeks or so) to keep the software running. All these made a lot of users switch to KiCad and are fuelling the development and the community support. 

Unlike before most of the component sellers like [mouser](http://mouser.componentsearchengine.com/library/kicad), [digikey](https://www.digikey.com/en/resources/design-tools/kicad)... have KiCad libraries for the components. Also online libraries like [SnapEDA](https://www.snapeda.com/home/) and [Ultra Librarian](https://www.ultralibrarian.com/) also have vast KiCad libraries.

[Video resources: Contextual Electronics](https://www.youtube.com/user/contextualelectronic/playlists)


---
[Back to Summary](../summary.md)
