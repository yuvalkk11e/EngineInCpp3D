
template <class T>
void CameraHandle<T>::MouseMovedCamera(sf::Event event)
{
	int x = event.mouseMove.x;
	int y = event.mouseMove.y;

	int xmoved = (x - xpos)*sensitivity;
	int ymoved = (y - ypos)*sensitivity;

	Matrix m = TransformationMatrixes::rotationMatrix(ymoved, xmoved, 0);
	buffer.TranforMatrix(m);
	Vector3 rotation = buffer.getRotation();
	buffer.setRotations(rotation.GetValues(0) + xmoved, rotation.GetValues(1) + ymoved, rotation.GetValues(2));

	xpos = x;
	ypos = y;

}