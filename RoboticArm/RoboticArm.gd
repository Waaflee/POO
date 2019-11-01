extends Spatial

var gravity = -12  # strength of gravity Vector3.DOWN * 12
var speed = 4  # movement speed
var jump_speed = 6  # jump strength
var spin = 1  # rotation speed

func _ready():
	pass

func _process(delta):
#	get_node("Prisma1").rotate_z(-delta * 2)rotate_object_local(Vector3(1, 0, 0), PI)
#	get_node("Prisma1").get_node("Prisma2").rotate_z(delta * 10)
#	get_node("Prisma1").get_node("Prisma2").get_node("Prisma3").rotate_x(delta * 0.5)
#	get_node("Prisma1").get_node("Prisma2").get_node("Prisma3").rotate_object_local(Vector3(1, 0, 0), 0.01)
	pass