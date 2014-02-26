-- MONKEY

-- Colours
white = gr.material({1.0, 1.0, 1.0}, {0.1, 0.1, 0.1}, 10)
black = gr.material({0.0, 0.0, 0.0}, {0.1, 0.1, 0.1}, 10)
beige = gr.material({1.0, 0.92, 0.80}, {0.1, 0.1, 0.1}, 10)
darkbrown = gr.material({0.4, 0.26, 0.13}, {0.1, 0.1, 0.1}, 10)
indigo = gr.material({0.29, 0.0, 0.51}, {0.1, 0.1, 0.1}, 10)
yellow = gr.material({1.0, 1.0, 0.0}, {0.1, 0.1, 0.1}, 10)


-- Root Node
scene = gr.node('scene')
scene:scale(0.8, 0.8, 0.8)

-- Collision Node
--bound = gr.cube('bound')
--scene:add_child(bound)
--bound:set_material(white)
--bound:scale(2.0, 2.0, 8.0)

-- Boat Node
boatNode = gr.node('BoatNode')
scene:add_child(boatNode)
boatNode:translate(1.2, -2.3, 5.0)
boatNode:rotate('y', 90)

-- Base of banana
base = gr.sphere('base')
boatNode:add_child(base)
base:set_material(yellow)
base:translate(0.18, 0.0, 0.0)
base:scale(2.2, 0.86, 0.86)

base2 = gr.sphere('base2')
boatNode:add_child(base2)
base2:set_material(yellow)
base2:translate(1.54, 0.28, 0.0)
base2:rotate('z', 25)
base2:scale(2.0, 0.86, 0.86)

-- Bottom end of banana
bottom = gr.cylinder('bottom', 0.5, 1.3)
boatNode:add_child(bottom)
bottom:set_material(yellow)
bottom:translate(-1.4, 0.11, 0.0)
bottom:rotate('y', -90)
bottom:rotate('x', -25)
bottom:scale(0.5, 0.5, 1.4)

endtip = gr.sphere('endtip')
boatNode:add_child(endtip)
endtip:set_material(black)
endtip:translate(-2.7, 0.7, 0.0)
endtip:scale(0.25, 0.25, 0.25)

-- Top end of banana
top = gr.cylinder('top', 1.3, 0.3)
boatNode:add_child(top)
top:set_material(yellow)
top:translate(4.05, 2.05, 0.0)
top:rotate('y', -90)
top:rotate('x', 41)
top:scale(0.5, 0.5, 1.8)

stem = gr.cylinder('stem', 1.0, 1.0)
boatNode:add_child(stem)
stem:set_material(black)
stem:translate(4.4, 2.35, 0.0)
stem:rotate('y', -90)
stem:rotate('x', 41)
stem:scale(0.15, 0.15, 0.6)


-- Monkey Node
monkeyNode = gr.node('Monkey')
scene:add_child(monkeyNode)
monkeyNode:translate(1.22, -0.3, 5.0)
monkeyNode:rotate('y', 180)
monkeyNode:rotate('x', 30)
monkeyNode:scale(1.1, 1.1, 1.1)

-- Torso
torso = gr.sphere('Torso')
monkeyNode:add_child(torso)
torso:set_material(darkbrown)
torso:scale(1.0, 1.3, 1.0)

-- Stomach
stomach = gr.sphere('Stomach')
monkeyNode:add_child(stomach)
stomach:set_material(beige)
stomach:translate(0.0, 0.0, 0.6)
stomach:scale(0.75, 1.0, 0.4)

bellybutton = gr.sphere('BellyButton')
monkeyNode:add_child(bellybutton)
bellybutton:set_material(black)
bellybutton:translate(0.0, -0.4, 0.95)
bellybutton:scale(0.15, 0.03, 0.03)

-- Tail
tail1 = gr.cylinder('Tail1', 1.0, 1.0)
monkeyNode:add_child(tail1)
tail1:set_material(darkbrown)
tail1:translate(0.0, -0.3, -1.5)
tail1:rotate('x', 20)
tail1:scale(0.15, 0.15, 1.0)

tail2 = gr.sphere('Tail2')
monkeyNode:add_child(tail2)
tail2:set_material(darkbrown)
tail2:translate(0.0, -0.3, -1.5)
tail2:scale(0.15, 0.15, 0.15)

tail3 = gr.cylinder('Tail3', 1.0, 1.0)
monkeyNode:add_child(tail3)
tail3:set_material(darkbrown)
tail3:translate(0.15, 0.15, -1.9)
tail3:rotate('y', -20)
tail3:rotate('x', 45)
tail3:scale(0.15, 0.15, 0.6)

tail4 = gr.sphere('Tail4')
monkeyNode:add_child(tail4)
tail4:set_material(darkbrown)
tail4:translate(0.15, 0.15, -1.9)
tail4:scale(0.15, 0.15, 0.15)

-- Shoulders
shouldersnode = gr.node('ShouldersNode')
monkeyNode:add_child(shouldersnode)

shouldersjoint = gr.joint('ShouldersJoint', {0.0, 0.0, 0.0}, {-30.0, 0.0, 30.0})
shouldersnode:add_child(shouldersjoint)
shouldersjoint:translate(0.0, 0.75, 0.0)

-- Hips
hipsnode = gr.node('HipsNode')
monkeyNode:add_child(hipsnode)

hipsjoint = gr.joint('HipsJoint', {0.0, 0.0, 0.0}, {-20.0, 0.0, 20.0})
hipsnode:add_child(hipsjoint)
hipsjoint:translate(0.0, -0.6, 0.0)
hipsjoint:rotate('x', -40)

-- Neck
neckjoint = gr.joint('NeckJoint', {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0})
shouldersjoint:add_child(neckjoint)
neckjoint:translate(0.0, 1.2, 0.0)

neck = gr.cylinder('Neck', 1.0, 1.0)
neckjoint:add_child(neck)
neck:set_material(darkbrown)
neck:translate(0.0, -0.4, -0.2)
neck:rotate('x', 90)
neck:scale(0.4, 0.5, 0.4)

-- Head
headjoint = gr.joint('HeadJoint', {-5.0, 0.0, 20.0}, {-20.0, 0.0, 20.0})
neckjoint:add_child(headjoint)
headjoint:translate(0.0, 0.1, -0.5)
headjoint:rotate('x', -30)

headupper = gr.sphere('HeadUpper')
headjoint:add_child(headupper)
headupper:set_material(darkbrown)
headupper:translate(0.0, 0.4, 0.0)
headupper:scale(0.9, 0.7, 1.0)

headlower = gr.sphere('HeadLower')
headjoint:add_child(headlower)
headlower:set_material(darkbrown)
headlower:translate(0.0, -0.2, 0.0)
headlower:scale(1.1, 0.7, 1.0)

-- Face
faceupper1 = gr.sphere('FaceUpper1')
headjoint:add_child(faceupper1)
faceupper1:set_material(beige)
faceupper1:translate(0.25, 0.2, 0.95)
faceupper1:scale(0.35, 0.4, 0.15)

faceupper2 = gr.sphere('FaceUpper2')
headjoint:add_child(faceupper2)
faceupper2:set_material(beige)
faceupper2:translate(-0.25, 0.2, 0.95)
faceupper2:scale(0.35, 0.4, 0.15)

facelower = gr.sphere('FaceLower')
headjoint:add_child(facelower)
facelower:set_material(beige)
facelower:translate(0.0, -0.35, 0.8)
facelower:scale(0.8, 0.45, 0.5)

-- Nose
nostril1 = gr.sphere('Nostril1')
headjoint:add_child(nostril1)
nostril1:set_material(black)
nostril1:translate(-0.1, -0.2, 1.3)
nostril1:rotate('z', -45)
nostril1:scale(0.1, 0.05, 0.05)

nostril2 = gr.sphere('Nostril2')
headjoint:add_child(nostril2)
nostril2:set_material(black)
nostril2:translate(0.1, -0.2, 1.3)
nostril2:rotate('z', 45)
nostril2:scale(0.1, 0.05, 0.05)

-- Ears
ear1 = gr.sphere('Ear1')
headjoint:add_child(ear1)
ear1:set_material(darkbrown)
ear1:translate(0.8, 0.5, 0.2)
ear1:scale(0.4, 0.4, 0.2)

innerear1 = gr.sphere('InnerEar1')
headjoint:add_child(innerear1)
innerear1:set_material(beige)
innerear1:translate(0.8, 0.45, 0.34)
innerear1:scale(0.25, 0.25, 0.1)

ear2 = gr.sphere('Ear2')
headjoint:add_child(ear2)
ear2:set_material(darkbrown)
ear2:translate(-0.8, 0.5, 0.2)
ear2:scale(0.4, 0.4, 0.2)

innerear2 = gr.sphere('InnerEar2')
headjoint:add_child(innerear2)
innerear2:set_material(beige)
innerear2:translate(-0.8, 0.45, 0.34)
innerear2:scale(0.25, 0.25, 0.1)

-- mouth
mouth1 = gr.sphere('Mouth1')
headjoint:add_child(mouth1)
mouth1:set_material(black)
mouth1:translate(0.0, -0.7, 1.1)
mouth1:scale(0.2, 0.03, 0.1)

mouth2 = gr.sphere('Mouth2')
headjoint:add_child(mouth2)
mouth2:set_material(black)
mouth2:translate(0.23, -0.66, 1.1)
mouth2:rotate('z', 18)
mouth2:scale(0.2, 0.03, 0.1)

mouth3 = gr.sphere('Mouth3')
headjoint:add_child(mouth3)
mouth3:set_material(black)
mouth3:translate(-0.23, -0.66, 1.1)
mouth3:rotate('z', -18)
mouth3:scale(0.2, 0.03, 0.1)

-- eyes
eye1 = gr.sphere('Eye1')
headjoint:add_child(eye1)
eye1:set_material(white)
eye1:translate(0.2, 0.2, 1.05)
eye1:scale(0.23, 0.27, 0.1)

eye2 = gr.sphere('Eye2')
headjoint:add_child(eye2)
eye2:set_material(white)
eye2:translate(-0.2, 0.2, 1.05)
eye2:scale(0.23, 0.27, 0.1)

pupil1 = gr.sphere('pupil1')
headjoint:add_child(pupil1)
pupil1:set_material(black)
pupil1:translate(0.18, 0.15, 1.1)
pupil1:scale(0.14, 0.18, 0.1)

pupil2 = gr.sphere('pupil2')
headjoint:add_child(pupil2)
pupil2:set_material(black)
pupil2:translate(-0.18, 0.15, 1.1)
pupil2:scale(0.14, 0.18, 0.1)

-- Right Upper Arm
rupperarmjoint = gr.joint('rightUpperArmJoint', {-30.0, 0.0, 30.0}, {0.0, 0.0, 0.0})
shouldersjoint:add_child(rupperarmjoint)
rupperarmjoint:translate(-0.8, 0.0, 0.0)
rupperarmjoint:rotate('x', -70)

rupperarm = gr.sphere('rightUpperArm')
rupperarmjoint:add_child(rupperarm)
rupperarm:set_material(darkbrown)
rupperarm:translate(0.0, -0.5, 0.0)
rupperarm:scale(0.35, 0.7, 0.4)

-- Left Upper Arm
lupperarmjoint = gr.joint('leftUpperArmJoint', {-30.0, 0.0, 30.0}, {0.0, 0.0, 0.0})
shouldersjoint:add_child(lupperarmjoint)
lupperarmjoint:translate(0.8, 0.0, 0.0)
lupperarmjoint:rotate('x', -70)

lupperarm = gr.sphere('leftUpperArm')
lupperarmjoint:add_child(lupperarm)
lupperarm:set_material(darkbrown)
lupperarm:translate(0.0, -0.5, 0.0)
lupperarm:scale(0.35, 0.7, 0.4)

-- Right Thigh
rthighjoint = gr.joint('rightThighJoint', {-30.0, 0.0, 30.0}, {0.0, 0.0, 0.0})
hipsjoint:add_child(rthighjoint)
rthighjoint:translate(-0.75, 0.0, 0.0)

rthigh = gr.sphere('rightThigh')
rthighjoint:add_child(rthigh)
rthigh:set_material(darkbrown)
rthigh:translate(0.0, -0.6, 0.0)
rthigh:scale(0.35, 0.7, 0.4)

-- Left Thigh
lthighjoint = gr.joint('leftThighJoint', {-30.0, 0.0, 30.0}, {0.0, 0.0, 0.0})
hipsjoint:add_child(lthighjoint)
lthighjoint:translate(0.75, 0.0, 0.0)

lthigh = gr.sphere('leftThigh')
lthighjoint:add_child(lthigh)
lthigh:set_material(darkbrown)
lthigh:translate(0.0, -0.6, 0.0)
lthigh:scale(0.35, 0.7, 0.4)

-- Right Forearm
rforearmjoint = gr.joint('rightForearmJoint', {0.0, 0.0, 45.0}, {0.0, 0.0, 0.0})
rupperarmjoint:add_child(rforearmjoint)
rforearmjoint:translate(0.0, -1.35, 0.0)
rforearmjoint:rotate('x',-30)

rforearm = gr.sphere('rightForearm')
rforearmjoint:add_child(rforearm)
rforearm:set_material(darkbrown)
rforearm:translate(0.0, -0.15, 0.0)
rforearm:scale(0.3, 0.7, 0.3)

-- Left Forearm
lforearmjoint = gr.joint('leftForearmJoint', {0.0, 0.0, 45.0}, {0.0, 0.0, 0.0})
lupperarmjoint:add_child(lforearmjoint)
lforearmjoint:translate(0.0, -1.35, 0.0)
lforearmjoint:rotate('x', -30)

lforearm = gr.sphere('leftForearm')
lforearmjoint:add_child(lforearm)
lforearm:set_material(darkbrown)
lforearm:translate(0.0, -0.15, 0.0)
lforearm:scale(0.3, 0.7, 0.3)

-- Right Calf
rcalfjoint = gr.joint('rightCalfJoint', {0.0, 0.0, 45.0}, {0.0, 0.0, 0.0})
rthighjoint:add_child(rcalfjoint)
rcalfjoint:translate(0.0, -1.35, -0.3)
rcalfjoint:rotate('x', 65)

rcalf = gr.sphere('rightCalf')
rcalfjoint:add_child(rcalf)
rcalf:set_material(darkbrown)
rcalf:translate(0.0, -0.15, 0.0)
rcalf:scale(0.3, 0.7, 0.3)

-- Left Calf
lcalfjoint = gr.joint('leftCalfJoint', {0.0, 0.0, 45.0}, {0.0, 0.0, 0.0})
lthighjoint:add_child(lcalfjoint)
lcalfjoint:translate(0.0, -1.35, -0.3)
lcalfjoint:rotate('x', 65)

lcalf = gr.sphere('leftCalf')
lcalfjoint:add_child(lcalf)
lcalf:set_material(darkbrown)
lcalf:translate(0.0, -0.15, 0.0)
lcalf:scale(0.3, 0.7, 0.3)

-- Right Hand
rhandjoint = gr.joint('rightHandJoint', {0.0, 0.0, 0.0}, {-30.0, 0.0, 30.0})
rforearmjoint:add_child(rhandjoint)
rhandjoint:translate(0.0, -0.9, 0.0)
rhandjoint:rotate('y', -90)

rhand = gr.sphere('rightHand')
rhandjoint:add_child(rhand)
rhand:set_material(beige)
rhand:scale(0.3, 0.5, 0.2)

rthumb = gr.sphere('rightThumb')
rhandjoint:add_child(rthumb)
rthumb:set_material(beige)
rthumb:translate(0.25, 0.1, 0.0)
rthumb:rotate('z', -45)
rthumb:scale(0.3, 0.15, 0.15)

-- Left Hand
lhandjoint = gr.joint('leftHandJoint', {0.0, 0.0, 0.0}, {-30.0, 0.0, 30.0})
lforearmjoint:add_child(lhandjoint)
lhandjoint:translate(0.0, -0.9, 0.0)
lhandjoint:rotate('y', -90)

lhand = gr.sphere('leftHand')
lhandjoint:add_child(lhand)
lhand:set_material(beige)
lhand:scale(0.3, 0.5, 0.2)

lthumb = gr.sphere('leftThumb')
lhandjoint:add_child(lthumb)
lthumb:set_material(beige)
lthumb:translate(-0.25, 0.1, 0.0)
lthumb:rotate('z', 45)
lthumb:scale(0.3, 0.15, 0.15)

-- Right Foot
rfootjoint = gr.joint('rightFootJoint', {0.0, 0.0, 0.0}, {-30.0, 0.0, 30.0})
rcalfjoint:add_child(rfootjoint)
rfootjoint:translate(0.0, -0.8, 0.0)

rfoot = gr.sphere('rightFoot')
rfootjoint:add_child(rfoot)
rfoot:set_material(beige)
rfoot:scale(0.3, 0.2, 0.5)
rfoot:translate(0.0, 0.0, 0.6)

rtoe = gr.sphere('rightToe')
rfootjoint:add_child(rtoe)
rtoe:set_material(beige)
rtoe:translate(0.25, 0.0, 0.1)
rtoe:rotate('y', -45)
rtoe:scale(0.3, 0.15, 0.15)

-- Left Foot
lfootjoint = gr.joint('leftFootJoint', {0.0, 0.0, 0.0}, {-30.0, 0.0, 30.0})
lcalfjoint:add_child(lfootjoint)
lfootjoint:translate(0.0, -0.8, 0.0)

lfoot = gr.sphere('leftFoot')
lfootjoint:add_child(lfoot)
lfoot:set_material(beige)
lfoot:scale(0.3, 0.2, 0.5)
lfoot:translate(0.0, 0.0, 0.6)

ltoe = gr.sphere('leftToe')
lfootjoint:add_child(ltoe)
ltoe:set_material(beige)
ltoe:translate(-0.3, 0.0, 0.1)
ltoe:rotate('y', 45)
ltoe:scale(0.25, 0.15, 0.15)


return scene
