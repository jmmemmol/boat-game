-- BUOY

-- Colours
brown = gr.material({0.55, 0.27, 0.07}, {0.1, 0.1, 0.1}, 10)

-- Textures
crateTexture = gr.texture('data/textures/crateTexture.png')


-- Root Node
root = gr.node('Root')

-- crate
crateNode = gr.cube('Crate')
scene:add_child(crateNode)
crateNode:set_material(brown)
crateNode:set_texture(crateTexture)
crateNode:scale(3.0, 3.0, 3.0)

return root