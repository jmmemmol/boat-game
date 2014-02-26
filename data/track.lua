-- TRACK

-- Colours
black = gr.material({1.0, 1.0, 1.0}, {0.1, 0.1, 0.1}, 10)


-- Root Node
scene = gr.node('scene')

outerWall = gr.cylinder('OuterWall', 1.0, 1.0)
scene:add_child(outerWall)
outerWall:set_material(black)
outerWall:translate(0.0, 1.0, -200.0)
outerWall:scale(200.0, 2.0, 200.0)
outerWall:rotate('x', 90)

innerWall = gr.cylinder('InnerWall', 1.0, 1.0)
scene:add_child(innerWall)
innerWall:set_material(black)
innerWall:translate(0.0, 1.0, -195)
innerWall:scale(150.0, 2.0, 150.0)
innerWall:rotate('x', 90)

return scene
