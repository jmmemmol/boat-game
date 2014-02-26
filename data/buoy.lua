-- BUOY

-- Colours
red = gr.material({1.0, 0.0, 0.0}, {0.1, 0.1, 0.1}, 10)


-- Root Node
scene = gr.node('scene')

-- boat
buoyNode = gr.sphere('Buoy')
scene:add_child(buoyNode)
buoyNode:set_material(red)
buoyNode:scale(2.0, 2.0, 2.0)

return scene
