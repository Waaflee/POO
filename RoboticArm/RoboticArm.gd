extends Spatial

onready var prisma_1 := get_node("Prisma1")
onready var prisma_2 := get_node("Prisma1").get_node("Prisma2")
onready var prisma_3 := get_node("Prisma1").get_node("Prisma2").get_node("Prisma3")
onready var tween := get_node("Tween")
var pinza_abierta = false
var GRADOS := [0, 0, 0]
var selected = 1

func _ready():
	pass

func _process(delta):
	if Input.is_action_just_pressed("ui_accept"):
		selected += 1
		if selected > 3:
			selected = 1
		print(selected)
	if Input.is_action_just_pressed("ui_up"):
		GRADOS[selected - 1] += 10
		GRADOS[selected - 1] = clamp(GRADOS[selected - 1], -90, 90)
		rotar_articulacion(selected, GRADOS[selected - 1], 90)
		print(GRADOS[selected - 1])
	if Input.is_action_just_pressed("ui_down"):
		GRADOS[selected - 1] -= 10
		rotar_articulacion(selected, GRADOS[selected - 1], 90)
		print(GRADOS[selected - 1])

func abrir_pinza():
	pinza_abierta = true
	tween.interpolate_property(prisma_3.get_node("Pinza1"), "rotation_degrees", prisma_3.get_node("Pinza1").rotation_degrees, Vector3(0, 30, 0), 0.5, Tween.TRANS_LINEAR, Tween.EASE_IN, 0)
	tween.interpolate_property(prisma_3.get_node("Pinza2"), "rotation_degrees", prisma_3.get_node("Pinza2").rotation_degrees, Vector3(0, -30, 0), 0.5, Tween.TRANS_LINEAR, Tween.EASE_IN, 0)

func cerrar_pinza():
	pinza_abierta = false
	tween.interpolate_property(prisma_3.get_node("Pinza1"), "rotation_degrees", prisma_3.get_node("Pinza1").rotation_degrees, Vector3(0, 0, 0), 0.5, Tween.TRANS_LINEAR, Tween.EASE_IN, 0)
	tween.interpolate_property(prisma_3.get_node("Pinza2"), "rotation_degrees", prisma_3.get_node("Pinza2").rotation_degrees, Vector3(0, 0, 0), 0.5, Tween.TRANS_LINEAR, Tween.EASE_IN, 0)
	
func toggle_pinza():
	if pinza_abierta:
		cerrar_pinza()
	else:
		abrir_pinza()
	tween.start()

func rotar_articulacion(articulacion: int, grados: float, speed: float = 45):
		grados = clamp(grados, -90, 90)
		if speed == 0:
			speed = 45
		var time = abs(grados / speed) + 1
		if articulacion == 1:
			tween.interpolate_property(prisma_1, "rotation_degrees", prisma_1.rotation_degrees, Vector3(grados, 0 , 0), time, Tween.TRANS_LINEAR, Tween.EASE_IN, 0)
		if articulacion == 2:
			tween.interpolate_property(prisma_2, "rotation_degrees", prisma_2.rotation_degrees, Vector3(grados, 0, 0), time, Tween.TRANS_LINEAR, Tween.EASE_IN, 0)
		if articulacion == 3:
			tween.interpolate_property(prisma_3, "rotation_degrees", prisma_3.rotation_degrees, Vector3(grados, 0, 0), time, Tween.TRANS_LINEAR, Tween.EASE_IN, 0)
		tween.start()
		
func _on_Timer_timeout():
	toggle_pinza()