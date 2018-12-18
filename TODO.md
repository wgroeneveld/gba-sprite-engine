
## To do

- Get software interrupts to work and replace `vblank()` while cycles
- Further reduce `update()` instruction cycles by removing `updateOam()` on each update - only change what is needed. Might cause breaking API changes.
- Replace `VECTOR` return values everywhere with `GBAVector`, refactor to `Vector2d`. Check for performance hits; copying value-objects in update loop is not a good idea. 
- Rename `updateSpritesInScene` to `reRenderAll`

## To investigate

- Affine sprites [overwrite the flip flag](https://www.coranac.com/tonc/text/regobj.htm), should the flip functions do something or not? 
- Would it be possible to dynamically update tiles for a sprite within the same scene? What about size differences? 
- How does saving/loading data to and from RAM work? Can I serialize objects? For instance, binary header-only serialization with [Cereral](https://uscilab.github.io/cereal/quickstart.html)