/// <summary>
/// Boîte à outils avec des alias et des méthodes utiles.
/// </summary>
namespace toolbox
{
	template<typename T, size_t WIDTH, size_t HEIGHT> using Array2D = std::array<std::array<T, WIDTH>, HEIGHT>;
}