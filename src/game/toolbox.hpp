/// <summary>
/// Bo�te � outils avec des alias et des m�thodes utiles.
/// </summary>
namespace toolbox
{
	template<typename T, size_t WIDTH, size_t HEIGHT> using Array2D = std::array<std::array<T, WIDTH>, HEIGHT>;
}